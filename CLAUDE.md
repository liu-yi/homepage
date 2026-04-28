# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 项目概述

基于 **Docsify** 的学术个人主页，部署在 Vercel（`liuyi.chat`）。纯静态站点，无服务端运行时，无构建步骤——Vercel 直接托管仓库文件。

## 开发命令

```bash
# 本地预览（任意静态服务器均可）
python3 -m http.server 4173
# 访问 http://localhost:4173/index.html

# 编辑 public/css/styles.css 后，压缩生成 styles.min.css
node minify.js          # 或: bash minify.sh
# 首次需要: npm install --save-dev clean-css-cli
```

无测试套件、无 linter、无 CI 流水线。修改后通过浏览器手动验证。

## 部署方式

Docsify 是运行时 SPA 框架，**不需要构建步骤**。`index.html` 在浏览器端动态加载 Markdown 内容并渲染为页面。

- Vercel 配置（`vercel.json`）使用 `@vercel/static`，直接提供静态文件服务
- 推送到 `main` 分支即自动部署，无需配置 Build Command 或 Output Directory
- `index.html` 和所有 `.md` 文件设置了 `no-cache` 头，确保内容更新即时生效
- 自定义域名通过 `CNAME` 文件（`liuyi.chat`）配置

## 架构

**Docsify SPA 模式**：`index.html` 是唯一入口，包含 Docsify 配置、主题切换、插件和脚本加载顺序。

**核心文件**：
- **`index.html`** — 入口文件。Docsify 配置（`window.$docsify`）、主题切换逻辑、AMap 插件、Google/百度统计
- **`docs/cv.md`** — 首页（Docsify `homepage` 配置指向此处）。使用 Vue 3 模板语法实现头像悬停、中英文名切换等交互
- **`publications/README.md`** — 论文列表页，配合 `public/js/publications.js` 实现搜索/筛选
- **`_navbar.md`** — 全局导航栏（`loadNavbar: true`）
- **`docs/_sidebar.md`** — docs/ 区域侧边栏

**内容目录**（均为 Markdown，由 Docsify 运行时渲染）：
- `research/` — 研究概述
- `publications/` — 论文列表（含 HTML/CSS 卡片）
- `teaching/` — 课程页面（cpp, crypto）
- `for-students/` — 招生信息
- `notes/` — 个人笔记草稿（未在导航中链接）

**静态资源**（`public/`）：
- `css/styles.css` → `styles.min.css`（源文件 → 压缩后）。`beautify.css` 为补充样式
- `js/` — 原生 JS 模块：`publications.js`（搜索筛选）、`dark-mode.js`、`avatar-ripple.js`、`cv-project-lang.js`、`progress-bar.js`、`address-toggle.js`、`docsify-scroll-to-top.js`
- `img/`、`icons/`、`fonts/`、`pdf/`、`cv/` — 静态媒体资源

**外部依赖**（全部通过 CDN 加载，无 npm 运行时依赖）：
- Docsify 4（SPA 路由/渲染）
- docsify-themeable、docsify-pagination、docsify-copy-code
- KaTeX（LaTeX 数学公式渲染）
- Prism.js（代码高亮）
- Vue 3（用于 `docs/cv.md` 模板）
- AMap SDK（CV 页面地图组件）

## 编码规范

- **缩进**：HTML/CSS 用 2 空格，JavaScript 用 4 空格
- **文件命名**：kebab-case（`dark-mode.js`、`styles.min.css`），目录小写
- **CSS**：主题变量统一在 `styles.css` 中用 CSS custom properties 定义，Markdown 内容中不写内联样式
- **JavaScript**：使用 IIFE 模式；操作 DOM 前先检查元素是否存在；保持函数短小纯净
- **Commit 信息**：使用 `区域: 摘要` 格式（如 `teaching: refresh syllabus links`），避免泛泛的 `update`

## 注意事项

- 编辑 `public/css/styles.css` 后**必须**运行 `node minify.js` 重新生成 `styles.min.css`——站点加载的是压缩版本
- 主题切换由 `index.html` 中 `window.THEME_TOGGLE_ENABLED` 控制（当前为 `false`，即禁用暗色模式切换）
- `docs/cv.md` 使用了 Vue 3 模板语法（`v-show`、`@click`、`{{ }}`），不是纯 Markdown
- AMap 地图仅在 CV 页面加载，有重试逻辑和页面导航时的清理机制
