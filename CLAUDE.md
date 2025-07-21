# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a personal academic website for **Yi Liu (刘逸)**, a cryptography researcher and lecturer at Jinan University. The site is built using **Docsify** (a documentation site generator) and serves as:

- **Personal CV/Resume**: Showcases education, research projects, publications, and teaching experience
- **Research Portfolio**: Details research interests in cryptography, secure multi-party computation, zero-knowledge proofs, and blockchain applications
- **Teaching Resources**: Contains course materials for C++ programming and advanced cryptography courses
- **Student Information**: Provides guidance for prospective students

## Technology Stack

- **Docsify**: Static site generator for documentation sites
- **Vue.js 3**: Interactive UI components (avatar hover effects, logo cycling)
- **KaTeX**: Mathematical formula rendering
- **Prism.js**: Code syntax highlighting
- **Custom CSS**: Responsive design with mobile support
- **CDN Resources**: Uses jsDelivr for optimized resource loading

## Site Structure

### Main Files
- `index.html`: Main Docsify configuration and entry point
- `CNAME`: Domain configuration (liuyi.pro)
- `docs/cv.md`: Main CV content (homepage)
- `public/css/styles.css`: Custom styling
- `public/css/styles.min.css`: Minified CSS

### Content Organization
- **docs/**: Main documentation pages
  - `cv.md`: Primary CV page
  - `home.md`: Landing page content
- **public/**: Static assets
  - `css/`: Stylesheets
  - `cv/`: PDF CV files
  - `icons/`: Social media icons
  - `img/`: Images and logos
  - `js/`: Custom JavaScript
- **teaching/**: Course materials and lecture notes
  - `cpp.md`: C++ programming course
  - `crypto.md`: Advanced cryptography course
  - `xcpp_fall23/`, `xcrypto_fall23/`: Historical course materials
- **research/**: Research project descriptions
- **publications/**: Complete publication list
- **notes/**: Research notes and technical documentation

### Interactive Features
- **Avatar Hover**: Logo cycles through 3 images on hover
- **Name Toggle**: English/Chinese name switching on hover
- **Progress Bar**: Scroll indicator at top of page
- **Responsive Design**: Mobile-optimized layout

## Development Workflow

### Local Development
```bash
# Serve locally (requires HTTP server)
python3 -m http.server 3000
# or
npx serve .

# Access at http://localhost:3000
```

### CSS Development
- Edit `public/css/styles.css` for development
- Minify to `public/css/styles.min.css` for production
- Use any CSS minifier tool or:
  ```bash
  npx clean-css-cli public/css/styles.css -o public/css/styles.min.css
  ```

### Content Updates
- **CV updates**: Edit `docs/cv.md`
- **Research content**: Edit `research/README.md`
- **Teaching materials**: Update relevant `.md` files in `teaching/`
- **Publications**: Update `publications/README.md`

### Asset Management
- **Images**: Place in `public/img/` or `research/img/`
- **PDFs**: Store in `public/cv/` or `public/pdf/`
- **Fonts**: Place custom fonts in `public/fonts/`

### Course Materials Structure
Teaching materials follow this pattern:
```
teaching/
├── [course].md           # Course overview
├── [course]_fall24/      # Semester-specific materials
│   ├── Lecture[XX]/      # Individual lectures
│   │   ├── Lecture[XX].pptx
│   │   └── code/         # Code examples
│   └── Lab[XX]/          # Lab sessions
│       ├── Lab[XX].pptx
│       └── code/
```

## Key Configuration Points

### Docsify Settings (index.html:56-76)
- `homepage: 'docs/cv.md'` - Sets CV as landing page
- `loadNavbar: true` - Loads navigation bar
- `mergeNavbar: true` - Merges navbar items
- `latex: {}` - KaTeX configuration for math rendering

### CSS Custom Properties
- `--theme-color: #558fb5` - Primary blue theme color
- `--base-font-size: 17px` - Base font size
- `--content-max-width: 70em` - Content width constraint

### CDN Dependencies
- Docsify (latest v4)
- Vue 3 (for interactive components)
- KaTeX (mathematical typesetting)
- Prism.js (code highlighting)
- Docsify plugins for enhanced functionality

## Domain & Deployment
- **Domain**: liuyi.pro (configured via CNAME)
- **Hosting**: Likely GitHub Pages or similar static hosting
- **CDN**: Uses jsDelivr for all external dependencies
- **Analytics**: Google Analytics (G-V6PJ8BXB1K) + Baidu Analytics