import { execFileSync } from 'node:child_process';
import { existsSync, mkdtempSync, readFileSync, readdirSync, rmSync, writeFileSync } from 'node:fs';
import { tmpdir } from 'node:os';
import { join, relative } from 'node:path';

const root = process.cwd();
const ignored = new Set(['.git', '.github', '.algoflow', 'node_modules']);
const folders = [];
function walk(folder) {
  for (const entry of readdirSync(folder, { withFileTypes: true })) {
    if (ignored.has(entry.name)) continue;
    const target = join(folder, entry.name);
    if (entry.isDirectory()) {
      if (existsSync(join(target, 'metadata.json'))) folders.push(target);
      else walk(target);
    }
  }
}
walk(root);
if (!folders.length) throw new Error('No AlgoFlow solution folders were found.');
let compiled = 0;
for (const folder of folders) {
  for (const required of ['README.md', 'metadata.json', 'test-cases.json']) if (!existsSync(join(folder, required))) throw new Error(`Missing ${required} in ${relative(root, folder)}`);
  const cpp = join(folder, 'solution.cpp');
  if (!existsSync(cpp)) continue;
  const code = readFileSync(cpp, 'utf8');
  const clean = code.replace(/\/\*[\s\S]*?\*\//g, '').replace(/\/\/.*$/gm, '');
  const temp = mkdtempSync(join(tmpdir(), 'algoflow-ci-'));
  const source = join(temp, 'check.cpp');
  const stubs = `#include <bits/stdc++.h>\nusing namespace std;\n${/\bstruct\s+ListNode\b/.test(clean) ? '' : 'struct ListNode { int val; ListNode *next; ListNode(int x=0,ListNode*n=nullptr):val(x),next(n){} };'}\n${/\bstruct\s+TreeNode\b/.test(clean) ? '' : 'struct TreeNode { int val; TreeNode *left,*right; TreeNode(int x=0):val(x),left(nullptr),right(nullptr){} };'}\n`;
  writeFileSync(source, stubs + code);
  try { execFileSync('g++', ['-std=c++20', '-fsyntax-only', source], { stdio: 'pipe' }); }
  catch (error) { throw new Error(`C++ compile check failed: ${relative(root, cpp)}\n${error.stderr?.toString() || error.message}`); }
  finally { rmSync(temp, { recursive: true, force: true }); }
  compiled++;
}
console.log(`Verified ${folders.length} solution folders; compiled ${compiled} C++ solutions.`);
