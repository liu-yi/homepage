#!/usr/bin/env node
// minify-css.js
const { execSync } = require('child_process');
const path = require('path');

const src = path.join('public', 'css', 'styles.css');
const dst = path.join('public', 'css', 'styles.min.css');

console.log('🔄 正在压缩 CSS...');
try {
  execSync(`npx clean-css-cli "${src}" -o "${dst}"`, { stdio: 'inherit' });
  console.log('✅ CSS 压缩完成！');
  console.log(`📁 已更新: ${dst}`);
  console.log('🎯 现在可以直接使用 styles.min.css');
} catch (e) {
  console.error('❌ 压缩失败，请确保已安装 clean-css-cli\nnpm i -D clean-css-cli');
  process.exit(1);
}