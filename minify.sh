#!/bin/bash
# 一键压缩CSS脚本

echo "🔄 正在压缩CSS..."
npx clean-css-cli public/css/styles.css -o public/css/styles.min.css
echo "✅ CSS压缩完成！"
echo "📁 已更新: public/css/styles.min.css"
echo "🎯 现在可以直接使用 styles.min.css"