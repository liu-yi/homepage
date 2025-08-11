# Project Overview

This directory contains the source files for Yi Liu's academic homepage (https://liuyi.pro). It is a static website built using Docsify, a lightweight documentation generator. The site presents Yi Liu's CV, research, publications, teaching, and other academic activities. It leverages various JavaScript libraries for functionality, including Vue.js for dynamic content, KaTeX for LaTeX rendering, and Prism.js for code highlighting.

The site is hosted on Vercel, as indicated by the `vercel.json` file. It uses Docsify plugins for features like theme switching, pagination, and copy code functionality. The main content is written in Markdown, with some HTML and embedded JavaScript for interactive elements like the profile picture toggle and the map display on the CV page.

# Key Files and Directories

- `index.html`: The main HTML file that initializes Docsify and loads the site.
- `docs/cv.md`: The primary content file for the CV page, containing personal information, publications, teaching, etc. It includes Vue.js components for interactivity.
- `_navbar.md`: Defines the site's navigation bar.
- `publications/README.md`: Contains the full list of publications.
- `for-students/README.md`: Information for prospective students about research interests and requirements.
- `research/README.md`: Details specific research areas like Private Function Evaluation and Data Trading.
- `teaching/README.md`: Lists undergraduate and postgraduate courses.
- `notes/README.md`: Links to various personal notes.
- `vercel.json`: Configuration for Vercel deployment.
- `public/`: Directory containing static assets like CSS, JavaScript, images, icons, and CV PDFs.

# Usage

This directory is used to maintain and update the content of the academic homepage. Content is primarily edited in Markdown files within the `docs`, `publications`, `for-students`, `research`, `teaching`, and `notes` directories. The site is automatically built and deployed by Vercel upon pushes to the repository.

To run the site locally for development or testing, a local server is needed to serve the `index.html` file. Docsify will dynamically load the Markdown content.

# Optimization Plan

This is a draft optimization plan for the homepage. It is not yet implemented.

## 1. Performance Optimization

-   **JavaScript Loading:**
    -   **Analysis & Prioritization:** Perform a critical path analysis to identify and prioritize JS/CSS essential for initial rendering (e.g., `docsify.min.js`, `theme-simple.css`).
    -   **Code Splitting & Lazy Loading:** Investigate lazy loading non-critical Docsify plugins (e.g., `docsify-pagination`, `docsify-copy-code`) to reduce initial load time. Consider bundling and minifying small, custom JS files (`public/js/*.js`) to reduce HTTP requests.
-   **CSS Optimization:**
    -   **Inline Critical CSS:** Inline the small, critical CSS required for above-the-fold rendering directly into `index.html` to eliminate render-blocking requests.
    -   **CSS Minification:** Ensure all CSS files, including `public/css/styles.min.css`, are minified and served with Gzip/Brotli compression.
-   **Image Optimization:**
    -   **Format & Compression:** Ensure all images (avatars like `logo.jpg`, `logo2.jpg`, `logo3.jpg`, and icons) are optimized for web. Use WebP where appropriate, compress JPGs/PNGs (e.g., TinyPNG), and keep SVGs lean.
    -   **Responsive Images:** Add `srcset` to profile images to serve different resolutions based on device screen.
    -   **Lazy Loading:** Add `loading="lazy"` attribute to images that are not immediately visible on initial page load.
-   **Font Optimization:**
    -   **Font Display:** Add `font-display: swap;` to `@font-face` rules (e.g., for KaTeX fonts) to improve perceived loading speed.
    -   **Critical Font Preloading:** Confirm that preloaded fonts are essential for the initial view.

## 2. User Experience & Accessibility (UX & a11y)

-   **Mobile Experience:**
    -   **Touch Targets:** Ensure all interactive elements (buttons, links) are easily tappable (min 44x44px) on mobile devices.
    -   **Layout Testing:** Test layout on various mobile screen sizes to ensure content flows correctly and avoids overflow or overlap.
-   **Accessibility:**
    -   **Semantic HTML:** Review and ensure proper use of semantic HTML tags (e.g., `<header>`, `<nav>`, `<main>`, `<section>`, `<footer>`).
    -   **Image Alt Text:** Provide descriptive `alt` attributes for all images, including profile pictures and social icons.
    -   **Color Contrast:** Check text/background color contrast ratios to meet WCAG 2.1 AA standards (minimum 4.5:1).
    -   **Keyboard Navigation:** Ensure all interactive elements (links, buttons, Vue components) are navigable and operable via keyboard (Tab key).
    -   **ARIA Attributes:** Add appropriate ARIA attributes to Vue-controlled interactive elements (e.g., avatar toggle, theme switcher) to aid screen readers.
-   **Theme Switching:**
    -   **Transitions:** Add smooth CSS transitions to the dark/light theme switch for a polished visual effect.

## 3. Content Management & SEO

-   **Content Management:**
    -   **Structured Data (Schema.org):** Add structured data (JSON-LD) to `index.html` for Person, research areas, publications to enhance search engine understanding.
    -   **Content Synchronization:** Establish a process to keep `publications/README.md` synchronized with external sources like Google Scholar or CVs.
-   **SEO (Search Engine Optimization):**
    -   **Keyword Optimization:** Refine Meta Description and Keywords to accurately reflect content and include relevant research keywords.
    -   **Internal Linking:** Review and ensure logical, functional internal links between pages (CV, Publications, Research, Teaching).
    -   **Sitemap:** Generate and submit a `sitemap.xml` to search engines to improve indexing.

## 4. Tech Stack & Dependencies

-   **CDN Reliability:** While CDNs offer performance, consider self-hosting critical, small libraries as a fallback or use a more reliable CDN provider.
-   **Dependency Updates:** Regularly check for updates to Docsify, its plugins, KaTeX, Prism.js, and other dependencies to benefit from new features and security patches.