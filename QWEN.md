# 项目背景：Yi Liu 学术主页

此目录包含了暨南大学密码学研究者 Yi Liu 学术主页的源代码和内容。该网站使用 Docsify 框架构建，该框架能够从 Markdown 文件动态生成网站。

## 项目概览

- **目的**：这是一个静态学术主页，用于展示 Yi Liu 的研究、出版物、教学和专业活动。
- **框架**：该网站使用 [Docsify](https://docsify.js.org/) 从 Markdown 生成文档站点。
- **托管**：网站配置为在 Vercel 上部署，`vercel.json` 文件对此进行了说明。
- **结构**：内容组织在 `docs/`（用于主页/CV）和 `publications/` 等目录的 Markdown 文件中。网站使用单一的 `index.html` 作为入口。
- **样式**：自定义 CSS 位于 `public/css/styles.css`（通过 `minify.sh` 脚本生成压缩版本 `styles.min.css`）。
- **脚本**：用于交互功能（如深色模式、出版物搜索）的自定义 JavaScript 位于 `public/js/`。**开发重要提示**：这是一个 Docsify 项目。因此，任何需要与 Docsify 生命周期交互（例如，在页面加载后运行代码）的自定义 JavaScript 最好实现为 Docsify 插件，并在 `index.html` 中的 `window.$docsify.plugins` 数组里注册。对于属于 Docsify 渲染内容的 DOM 元素的直接操作需要谨慎，通常需要 `hook.doneEach` 或 `hook.afterEach` 等钩子来确保元素存在。

## 关键文件与目录

- `index.html`：启动 Docsify 应用的主 HTML 文件。它包含了站点名称、导航的配置，并加载了各种 Docsify 插件（themeable, pagination, copy-code, 用于 LaTeX 的 katex 等）。它还集成了 Google Analytics 和 百度统计等外部服务。自定义的 Docsify 插件在此注册。
- `_navbar.md`：定义了站点的导航栏，包括指向不同版块的链接和一个主题切换开关。
- `docs/cv.md`：主页/CV 的主要内容文件，使用 Markdown 编写，并嵌入了 HTML 和 Vue.js 以实现动态元素（头像悬停效果、姓名切换、待办事项列表访问）。
- `publications/README.md`：包含完整的出版物列表，同样使用 Markdown 并嵌入 HTML 以实现布局和筛选。
- `public/`：包含静态资源，如图片 (`public/img/`)、图标 (`public/icons/`)、简历 PDF (`public/cv/`)、自定义 CSS (`public/css/`) 和自定义 JavaScript (`public/js/`)。
- `public/js/publications.js`：一个 Docsify 插件，为出版物页面添加搜索和筛选功能。它正确地使用 `window.$docsify.plugins` 进行注册，并利用 `hook.doneEach` 等钩子在内容加载后进行初始化。
- `public/js/dark-mode.js`：实现了深色/浅色主题切换逻辑，使用 `localStorage` 来记住用户的偏好设置。它也注册为一个 Docsify 插件。
- `vercel.json`：Vercel 部署配置，设置为将此项目视为静态站点。
- `minify.sh`：一个 bash 脚本，使用 `clean-css-cli` 来压缩自定义 CSS 文件。

## 开发与维护

- **内容更新**：大多数内容更改涉及编辑 `docs/` 和 `publications/` 目录中的 Markdown 文件。
- **样式调整**：修改 `public/css/styles.css`，然后运行 `./minify.sh` 来更新压缩版本。
- **脚本开发**：在添加依赖于 Docsify 页面加载/渲染的新交互功能时，应在 `public/js/` 中将其作为 Docsify 插件实现，并在 `index.html` 中注册。可参考 `public/js/publications.js` 了解正确的插件结构和注册方式。
- **部署**：该网站设计为静态托管。`vercel.json` 表明它使用 `@vercel/static` 构建过程部署在 Vercel 上。

此上下文信息应能帮助理解并修改网站的结构、内容和功能，同时牢记 Docsify 框架的具体要求和最佳实践。

## 优化与美化计划

在审阅代码后，以下是对主页进行进一步优化和美化的计划：

### 1. 主题与样式 (Theming and Styling)
- **微调配色方案 (Refine Color Scheme)**：
    - **现状**：当前主题功能完善，但可以考虑略微调整主色调，使其看起来更现代、更有活力或更专业。渐变色的使用是个不错的开始。
    - **行动项**：
        - 使用在线配色工具（如 Coolors, Adobe Color）探索新的、更和谐或更具现代感的配色方案。
        - 调整 `:root` 和 `[data-theme="dark"]` 中的 `--theme-color`、`--theme-color-light`、`--theme-color-dark` 以及 `--theme-color-gradient` 变量。
        - 为特定元素（如按钮、标签）引入点缀色 (Accent Colors)，增加视觉层次，确保与主色调协调。
- **探索 Docsify 主题 (Explore Docsify Themes)**：
    - **现状**：当前使用 `docsify-themeable` 的 `theme-simple.css`，这是一个干净的基础。
    - **行动项**：
        - 临时修改 `index.html` 中的 `<link rel="stylesheet" href="...">`，尝试 `docsify-themeable` 提供的其他预设主题（如 `theme-default.css`）。
        - 深入定制 `theme-simple`：查阅 [docsify-themeable 文档](https://jhildenbiddle.github.io/docsify-themeable/#/)，利用其丰富的 CSS 变量（如 `--sidebar-width`, `--code-font-size` 等）进行更精细的调整。
- **优化深色模式对比度 (Improve Dark Mode Contrast)**：
    - **现状**：深色模式下的基础文本与背景对比度很高，但辅助文本或链接颜色可能需要调整。
    - **行动项**：
        - 使用在线对比度检查工具，确保所有文本（特别是 `--text-muted`）在 `--bg-color` 上的对比度符合 WCAG 2.1 AA 级标准（至少 4.5:1）。
        - 微调深色模式下的文字颜色，使其更易读，例如将 `--text-muted` 调亮。
        - 为深色模式下的文字（如标题或普通段落）添加非常微妙的 `text-shadow`，以增强其在深色背景上的清晰度和“浮出”感。
- **改进排版 (Typography Improvements)**：
    - **现状**：使用了系统字体和自定义中文字体 `zhongsong`，性能良好。
    - **行动项**：
        - 确保 `zs.ttf` 字体文件经过压缩，并确认 `@font-face` 中的 `font-display: fallback;` 正在优化字体加载。
        - 考虑在标题或特定元素上添加 `font-feature-settings: 'kern' 1, 'liga' 1;` 以利用 OpenType 特性，提升西文排版质量。
        - 微调 `line-height` 和 `letter-spacing` 以优化阅读体验。

### 2. 交互性与用户体验 (Interactivity and User Experience)
- **平滑滚动行为 (Smooth Scroll Behavior)**：在 CSS 的 `html` 元素上添加 `scroll-behavior: smooth;`，使锚点链接导航更平滑。
- **头像交互 (Avatar Interaction)**：
    - 悬停切换图片和点击波纹效果很棒。确保在不同浏览器下表现一致。
    - 考虑在头像图片悬停时添加一个轻微的 `scale` 变换，以增强视觉效果。
- **出版物页面 (Publications Page)**：
    - 搜索和筛选功能良好。如果列表很大，考虑在筛选时添加视觉反馈（如加载指示器）。
    - 改进桌面端“悬停显示标签”的交互。可能稍显困惑。考虑始终显示关键标签（如 ePrint, DOI），仅隐藏次要标签，或使悬停区域更明显。
    - 当前的“带编号和徽章的列表”样式视觉上很独特。确保此设计在所有屏幕尺寸上都响应式且美观。
- **地址切换 (Address Toggle)**：点击切换中英文地址是巧妙的空间利用。确保点击区域清晰，过渡动画流畅。
- **返回顶部按钮 (Scroll-to-Top Button)**：按钮已存在。考虑优化其动画或根据滚动位置添加淡入淡出效果，使其更精致。
- **进度条 (Progress Bar)**：滚动进度条是不错的细节。确保其颜色与主题匹配且不过于显眼。

### 3. 性能与代码质量 (Performance and Code Quality)
- **CSS 压缩 (CSS Minification)**：`minify.sh` 脚本很好用。确保每次修改 CSS 后都运行它。如果引入构建步骤，可考虑将其自动化。
- **JavaScript 优化 (JavaScript Optimization)**：
    - 审查所有自定义 JS 文件 (`public/js/*.js`)，查找潜在的性能瓶颈，特别是可能被多次绑定的事件监听器。目前的插件通过 `setTimeout` 和移除监听器处理得还不错。
    - 确保所有自定义脚本都高效加载（目前大部分脚本使用 `defer` 是好的做法）。
    - 如果自定义 JS 量显著增长，考虑进行代码拆分，按页面只加载必要的脚本。
- **图片优化 (Image Optimization)**：确保所有图片（头像、图标、Logo）都经过适当压缩。SVG 图标是可扩展性和性能的好选择。

### 4. 内容与结构 (Content and Structure)
- **无障碍性 (Accessibility)**：在 Chrome DevTools 中运行 Lighthouse 等无障碍检查器，识别并修复如缺失 `alt` 文本（尽管大部分图片已有）、ARIA 标签和键盘导航等问题。
- **SEO (搜索引擎优化)**：`index.html` 中的元标签看起来很全面。确保 `docs/cv.md` 和 `publications/README.md` 中的内容也针对 SEO 进行了结构化处理，使用了适当的标题层级和描述性链接文本。
- **响应式设计 (Responsive Design)**：网站看起来基本响应式。在各种移动设备和屏幕尺寸上进行彻底测试，确保所有元素（特别是复杂的出版物列表和地图）都能很好地适应。

此计划侧重于通过对主题、交互性和性能进行细微优化，来增强现有坚实的基础，从而打造一个现代、快速且用户友好的学术主页。