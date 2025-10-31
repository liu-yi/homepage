# Repository Guidelines

## Project Structure & Module Organization
- `index.html` bootstraps the Docsify site and loads the shared scripts and styles—keep it lean for fast startups.
- Content sections live beside the root (`research/`, `teaching/`, `publications/`, `for-students/`, `miscellaneous/`) as Docsify-ready Markdown or HTML snippets.
- `public/` houses assets: editable CSS in `public/css/styles.css`, the generated bundle in `public/css/styles.min.css`, enhancements in `public/js/`, plus media subfolders (`img/`, `fonts/`, `pdf/`, `cv/`).
- Docsify navigation lives in `docs/` (`_navbar.md`, `_sidebar.md`, `cv.md`); edit these to update menus globally.
- Draft work can stay in `notes/`, but avoid committing large binaries outside `public/`.

## Build, Test, and Development Commands
- `npm install --save-dev clean-css-cli` once to make the minifier available.
- `node minify.js` or `bash minify.sh` rebuilds `public/css/styles.min.css`; run after touching `styles.css`.
- `python3 -m http.server 4173` from the repo root serves the site at `http://localhost:4173/index.html`; any static server with relative paths works.

## Coding Style & Naming Conventions
- Use two-space indentation for HTML/CSS and four-space indentation for JavaScript to stay consistent.
- Prefer descriptive, kebab-case filenames (`dark-mode.js`, `styles.min.css`) and lowercase folders.
- Centralize theme tokens as CSS custom properties in `styles.css`; keep content fragments free of inline styles.
- JavaScript utilities remain in IIFEs—check for DOM presence before updates and favor small, pure helpers.

## Testing Guidelines
- No automated suite exists; perform browser smoke tests (Chrome and Edge) after navigation, theming, or script changes.
- Validate dark-mode toggles, scroll-to-top behavior, and Docsify routing whenever `public/js/` changes.
- After minifying CSS, spot-check critical sections (navigation, hero, cards) to confirm styling persists.

## Commit & Pull Request Guidelines
- Use `area: summary` commit subjects (e.g., `teaching: refresh syllabus links`) rather than generic `update`.
- Pull requests should summarize the change, list impacted sections, and attach before/after screenshots for visual edits.
- Confirm `node minify.js` ran when CSS changed and link related issues or TODOs for traceability.

## Security & Deployment Notes
- `vercel.json` ships the site as static content; avoid server-side dependencies or build steps that require Node on deploy.
- Keep secrets and analytics tokens out of the repo; manage them in Vercel or environment configuration.
- Load new third-party scripts with `defer` and vet CDN availability to protect performance and privacy.
