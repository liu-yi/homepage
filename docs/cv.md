<div class="hero-section" id="hero">
  <div class="hero-content">
    <div id="intro">
      <div class="hero-profile">
        <div class="hero-image" @click="todo">
          <div id="avatar">
            <img v-show="!hover_avatar" src="public/img/logo.jpg" alt="Yi Liu's profile picture" v-on="{ mouseenter: mouseEnter, mouseleave: mouseLeave }">
            <img v-show="hover_avatar && todo_num % 2 == 0" src="public/img/logo2.jpg" alt="Yi Liu's alternative profile picture" v-on="{ mouseenter: mouseEnter, mouseleave: mouseLeave }">
            <img v-show="hover_avatar && todo_num % 2 == 1" src="public/img/logo3.jpg" alt="Yi Liu's third profile picture" v-on="{ mouseenter: mouseEnter, mouseleave: mouseLeave }">
          </div>
        </div>
        <div class="hero-info">
          <div class="hero-name" @mouseenter="hover_name = true" @mouseleave="hover_name = false">
            <span>{{ hover_name ? "刘   " : "Yi " }}</span>
            <span class="last">{{ hover_name ? "逸" : "Liu" }}</span>
          </div>
          <div class="hero-contact">
            <div class="email">i@liuyi.pro · liuyi@jnu.edu.cn</div>
          </div>
          <div class="hero-socials">
            <div>
              <a href="https://scholar.google.com.hk/citations?user=pKOcyg0AAAAJ" target="_blank" title="Google Scholar">
                <img src="public/icons/google-scholar.svg" alt="Google Scholar">
              </a>
              <a href="https://github.com/liu-yi" target="_blank" title="GitHub">
                <img src="public/icons/github.svg" alt="Github">
              </a>
              <a href="https://www.linkedin.com/in/liuyipro" target="_blank" title="LinkedIn">
                <img src="public/icons/linkedin-mono.svg" alt="LinkedIn">
              </a>
              <a href="https://www.zhihu.com/people/imliuyi" target="_blank" title="知乎">
                <img src="public/icons/zhihu.svg" alt="知乎">
              </a>
            </div>
          </div>
          <div class="hero-cv">
            <span v-if="display_todo"><a href="#/miscellaneous/todo">Todo</a><span class="divider-tight">·</span></span>
            <a target="_blank" href="public/cv/YiLIU-CV-en.pdf">CV</a><span class="divider-tight">·</span><a target="_blank" href="public/cv/YiLIU-CV-cn.pdf">简历</a><span class="divider-wide">|</span><a href="#/for-students/#main" class="recruit-link">招生<span class="recruit-dot"></span></a>
          </div>
        </div>
      </div>
    </div>
  </div>
  <button class="scroll-down-btn" onclick="document.getElementById('cv-page').scrollIntoView({ behavior: 'smooth' })" title="Scroll down">
    <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
      <path d="M6 9l6 6 6-6"/>
    </svg>
  </button>
</div>

<script>
  Vue.createApp({
    data: function(){
      return {
        hover_avatar: false,
        hover_name: false,
        todo_num : 0,
        display_todo: false,
      }
    },
    methods: {
      mouseEnter(event) {
        this.hover_avatar = true;
      },
      mouseLeave(event) {
        this.hover_avatar = false;
      },
      todo(){
        this.todo_num++; 
        if(this.todo_num == 10){
          this.display_todo = true
        }
      }
    }, 
  }).mount('#intro');
</script>

<div id="cv-page">

<br>

<!-- <div class="student-card">
  <div class="student-card-header">
    <svg class="student-icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.5">
      <path d="M12 14l9-5-9-5-9 5 9 5z"/>
      <path d="M12 14l6.16-3.422a12.083 12.083 0 01.665 6.479A11.952 11.952 0 0012 20.055a11.952 11.952 0 00-6.824-2.998 12.078 12.078 0 01.665-6.479L12 14z"/>
      <path d="M12 14l9-5-9-5-9 5 9 5zm0 0v7"/>
    </svg>
    <span>Looking for Students</span>
  </div>
  <div class="student-card-body">
    <p>I am available to supervise 2 Master's students each year. I am looking for self-motivated students with a solid background in computer science who are eager to explore research problems in <strong>cryptography</strong>, <strong>security</strong>, and <strong>privacy</strong>.</p>
    <p>For more information, see <a href="#/for-students/#main">Information For Prospective Students</a>. If you are interested, feel free to reach out via email!</p>
  </div>
</div>  -->


<!-- ## About Me
I am Yi Liu (刘逸), a lecturer at [College of Cyber Security](https://cybsec.jnu.edu.cn/), [Jinan University (JNU)](https://english.jnu.edu.cn/). My research interests broadly cover cryptography, computer security and privacy. Recently, I've been working on **secure multi-party computation**, **zero-knowledge proof**, **timed cryptography**, **blockchain-related applications**, etc.
 -->


## Education

<div class="cv-timeline">
  <div class="cv-timeline-item">
    <div class="cv-timeline-marker" aria-hidden="true"></div>
    <div class="cv-timeline-content">
      <div class="cv-timeline-header">
        <span class="cv-timeline-title">The University of Hong Kong (HKU)</span>
        <span class="cv-timeline-date">Sept. 2018 – Feb. 2023</span>
      </div>
      <div class="cv-timeline-meta">Ph.D. in Cryptography · Joint Ph.D. Programme with SUSTech</div>
      <ul class="cv-timeline-list">
        <li>Supervisor: <a href="https://www.cs.hku.hk/index.php/people/academic-staff/smyiu">Siu-Ming Yiu</a> (HKU) and <a href="https://dake98.github.io">Qi Wang</a> (SUSTech)</li>
        <li>Thesis: <a href="https://hub.hku.hk/handle/10722/327638" target="_blank">Private Function Evaluation: Improvements and Applications</a></li>
      </ul>
    </div>
  </div>
  <div class="cv-timeline-item">
    <div class="cv-timeline-marker" aria-hidden="true"></div>
    <div class="cv-timeline-content">
      <div class="cv-timeline-header">
        <span class="cv-timeline-title">Southern University of Science and Technology (SUSTech)</span>
        <span class="cv-timeline-date">Sept. 2014 – July 2018</span>
      </div>
      <div class="cv-timeline-meta">B.Eng. in Computer Science and Technology</div>
      <ul class="cv-timeline-list">
        <li>Thesis: An Evaluation System Based on Blockchain and Linkable Ring Signature</li>
        <ul><li>Best Thesis Award in the CSE Department, SUSTech</li></ul>
      </ul>
    </div>
  </div>
</div>

## Research Projects
<div class="cv-projects">
  <!-- <div class="cv-project-card">
    <button class="cv-project-lang-toggle" type="button" data-lang-state="en" aria-pressed="false" title="EN / 中文">
      <span class="cv-toggle-thumb" aria-hidden="true">EN</span>
    </button>
    <div class="cv-project-header">
      <span class="cv-project-title cv-lang" data-en="Research on the Design of New Secure Multi-Party Computation Protocols" data-zh="新型安全多方计算协议设计研究">Research on the Design of New Secure Multi-Party Computation Protocols</span>
    </div>
    <div class="cv-project-row">
      <span class="cv-project-meta cv-lang" data-en="Principal Investigator" data-zh="项目负责人">Principal Investigator</span>
      <span class="cv-project-date">2025 – 2026</span>
    </div>
    <div class="cv-project-support-row">
      <span class="cv-lang" data-en="Guangzhou Municipal Fundamental and Applied Basic Research Special Topic Young Doctoral “Sail” Project" data-zh="广州市基础与应用基础研究专题（青年博士“启航”项目）">Guangzhou Municipal Fundamental and Applied Basic Research Special Topic Young Doctoral “Sail” Project</span>
      <span class="cv-project-badge">Grant 2025A04J2146</span>
    </div>
  </div> -->
  <div class="cv-project-card">
    <button class="cv-project-lang-toggle" type="button" data-lang-state="en" aria-pressed="false" title="EN / 中文">
      <span class="cv-toggle-thumb" aria-hidden="true">EN</span>
    </button>
    <div class="cv-project-header">
      <span class="cv-project-title cv-lang" data-en="Design of Secure Multi-Party Computation Protocols in New Security Models" data-zh="新型安全模型中的安全多方计算协议设计">Design of Secure Multi-Party Computation Protocols in New Security Models</span>
    </div>
    <div class="cv-project-row">
      <span class="cv-project-meta cv-lang" data-en="Principal Investigator" data-zh="项目负责人">Principal Investigator</span>
      <span class="cv-project-date">2024 – 2026</span>
    </div>
    <div class="cv-project-support-row">
      <span class="cv-lang" data-en="Young Scientists Fund of the National Natural Science Foundation of China" data-zh="国家自然科学基金青年科学基金项目">Young Scientists Fund of the National Natural Science Foundation of China</span>
      <span class="cv-project-badge">Grant 62302194</span>
    </div>
  </div>
</div>


## Selected Publications

<div class="publist">

<span><a class="btn btn-outline-primary" style="font-size: 17px; width: 100%; padding: 2px" href="#/publications/?id=main">Full List of Publications</a></span>


- **Zero-Knowledge Protocols with PVC Security: Striking the Balance between Security and Efficiency** <span class="pubtag"><a class="emoji" href="https://doi.org/10.1007/978-981-95-3540-8_8" target="_blank">:link:</a></span>

    <u>**Yi Liu**</u>, Yipeng Song, Anjia Yang, Junzuo Lai

    The 27th International Conference on Information and Communications Security (**ICICS 2025**). <span class="pubtag"><a class="pubtag-link" href="https://eprint.iacr.org/2025/2146" target="_blank">ePrint</a></span>
    
    Nanjing, China. Oct. 2025.


- **Highly Efficient Actively Secure Two-Party Computation with One-Bit Advantage Bound** <span class="pubtag"><a class="emoji" href="https://doi.ieeecomputersociety.org/10.1109/SP61157.2025.00183" target="_blank">:link:</a></span>

    <u>**Yi Liu**</u>, Junzuo Lai, Peng Yang, Anjia Yang, Qi Wang, Siu-Ming Yiu, Jian Weng

    The 46th IEEE Symposium on Security and Privacy (**S&P 2025**). <span class="pubtag"><a class="pubtag-link" href="https://eprint.iacr.org/2025/614" target="_blank">ePrint</a></span> <span class="pubtag"><a class="pubtag-link" href="public/pdf/Oakland25.pdf" target="_blank">Poster</a></span>
    
    San Francisco, USA. May 2025.

- **Robust Publicly Verifiable Covert Security: Limited Information Leakage and Guaranteed Correctness with Low Overhead** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-981-99-8721-4_9" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Junzuo Lai, Qi Wang, Xianrui Qin, Anjia Yang, Jian Weng 

    The 29th International Conference on the Theory and Application of Cryptology and Information Security (**ASIACRYPT 2023**). <span class="pubtag"><a class="pubtag-link" href="https://eprint.iacr.org/2023/1392" target="_blank">ePrint</a></span>

    Guangzhou, China. Dec. 2023.

- **Towards Practical Homomorphic Time-Lock Puzzles: Applicability and Verifiability** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-031-17140-6_21" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 27th European Symposium on Research in Computer Security (**ESORICS 2022**). <span class="pubtag"><a class="pubtag-link" href="https://eprint.iacr.org/2022/585" target="_blank">ePrint</a></span>

    Copenhagen, Denmark. Sept. 2022.

- **Making Private Function Evaluation Safer, Faster, and Simpler** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-030-97121-2_13" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 25th International Conference on Practice and Theory of Public-Key Cryptography (**PKC 2022**). <span class="pubtag"><a class="pubtag-link" href="https://eprint.iacr.org/2021/1682" target="_blank">ePrint</a> <a class="btn btn-outline-primary" href="https://www.youtube.com/watch?v=Pv8zVTxacr0" target="_blank">Video</a></span>

    Virtual. March 2022.  

- **Improved Zero-Knowledge Argument of Encrypted Extended Permutation** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-030-88323-2_15" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 17th International Conference on International Conference on Information Security and Cryptology (**Inscrypt 2021**). <span class="pubtag"><a class="pubtag-link" href="https://eprint.iacr.org/2021/1430" target="_blank">ePrint</a></span>

    Virtual. Aug. 2021. 
    
- **Blind Polynomial Evaluation and Data Trading** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-030-78372-3_5" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 19th International Conference on Applied Cryptography and Network Security (**ACNS 2021**). <span class="pubtag"><a class="pubtag-link" href="https://eprint.iacr.org/2021/413" target="_blank">ePrint</a></span>

    Virtual. June 2021. 

- **An Improvement of Multi-Exponentiation with Encrypted Bases Argument: Smaller and Faster** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-030-71852-7_27" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 16th International Conference on International Conference on Information Security and Cryptology (**Inscrypt 2020**). <span class="pubtag"><a class="pubtag-link" href="https://eprint.iacr.org/2020/567" target="_blank">ePrint</a> </span>

    Guangzhou, China. Dec. 2020. 



</div>


## Teaching
<div class="cv-teaching-section">
  <div class="cv-teaching-heading">Undergraduate Courses</div>
  <div class="cv-teaching-cards">
    <div class="cv-teaching-card">
      <div class="cv-teaching-course">Theory of Provable Security</div>
      <div class="cv-teaching-terms">
        <span class="cv-teaching-term">Spring 2026</span>
      </div>
    </div>
    <div class="cv-teaching-card">
      <div class="cv-teaching-course">C++ Programming (+ Lab)</div>
      <div class="cv-teaching-terms">
        <span class="cv-teaching-term">Fall 2025</span>
        <span class="cv-teaching-term">Fall 2024</span>
        <span class="cv-teaching-term">Fall 2023</span>
      </div>
    </div>
    <div class="cv-teaching-card">
      <div class="cv-teaching-course">Practice of Advanced Cryptography</div>
      <div class="cv-teaching-terms">
        <span class="cv-teaching-term">Fall 2025</span>
      </div>
    </div>
    <div class="cv-teaching-card">
      <div class="cv-teaching-course">Public-Key Cryptography</div>
      <div class="cv-teaching-terms">
        <span class="cv-teaching-term">Spring 2025</span>
      </div>
    </div>
  </div>
</div>
<div class="cv-teaching-section">
  <div class="cv-teaching-heading">Graduate Courses</div>
  <div class="cv-teaching-cards">
    <div class="cv-teaching-card">
      <div class="cv-teaching-course">Advanced Cryptography</div>
      <div class="cv-teaching-terms">
        <span class="cv-teaching-term">Fall 2025</span>
        <span class="cv-teaching-term">Fall 2024</span>
        <span class="cv-teaching-term">Fall 2023</span>
      </div>
    </div>
  </div>
</div>


## Students

<div class="cv-teaching-section">
  <div class="cv-student-heading">Postgraduate Students</div>
  <div class="cv-student-cards">
    <div class="cv-student-card cv-student-current">
      <span class="cv-student-name">Yulong Du</span>
      <span class="cv-student-meta">Master, since 2025</span>
    </div>
    <div class="cv-student-card cv-student-current">
      <span class="cv-student-name">Cuiying Zhao</span>
      <span class="cv-student-meta">Master, since 2025</span>
    </div>
    <div class="cv-student-card cv-student-current">
      <span class="cv-student-name">Yunqi He</span>
      <span class="cv-student-meta">Master, since 2024</span>
    </div>
    <div class="cv-student-card cv-student-current">
      <span class="cv-student-name">Yipeng Song</span>
      <span class="cv-student-meta">Master, since 2023</span>
    </div>
  </div>
</div>
<div class="cv-teaching-section">
  <div class="cv-student-heading">Undergraduate Students</div>
  <div class="cv-student-cards">
    <div class="cv-student-card cv-student-current">
      <span class="cv-student-name">Tao Jiang</span>
      <span class="cv-student-meta">B.Eng. 2026</span>
    </div>
    <div class="cv-student-card cv-student-current">
      <span class="cv-student-name">Junsong He</span>
      <span class="cv-student-meta">B.Eng. 2026</span>
    </div>
    <div class="cv-student-card cv-student-current">
      <span class="cv-student-name">Yuanhao Zhuang</span>
      <span class="cv-student-meta">B.Eng. 2026</span>
    </div>
    <div class="cv-student-card">
      <span class="cv-student-name">Jiquan Yang</span>
      <span class="cv-student-meta">B.Eng. 2025</span>
    </div>
    <div class="cv-student-card">
      <span class="cv-student-name">Junjie Li</span>
      <span class="cv-student-meta">B.Eng. 2024 · Tencent</span>
    </div>
    <div class="cv-student-card">
      <span class="cv-student-name">Wanqing Li</span>
      <span class="cv-student-meta">B.Eng. 2024 · Midea</span>
    </div>
  </div>
</div>


## Professional Activities

<div class="cv-teaching-section">
  <div class="cv-teaching-heading">Journal Reviewers</div>
  <div class="cv-activity-tags">
    <span class="cv-activity-tag">IEEE Transactions on Dependable and Secure Computing</span>
    <span class="cv-activity-tag">IEEE Transactions on Industrial Informatics</span>
    <span class="cv-activity-tag">International Journal of Information Security</span>
    <span class="cv-activity-tag">Web Intelligence</span>
    <span class="cv-activity-tag">Frontiers of Computer Science</span>
  </div>
</div>
<div class="cv-teaching-section">
  <div class="cv-teaching-heading">Conference Reviewer</div>
  <div class="cv-activity-tags">
    <span class="cv-activity-tag">IEEE BSC@QRS (2022, 2021, 2020)</span>
  </div>
</div>
<div class="cv-teaching-section">
  <div class="cv-teaching-heading">Membership</div>
  <div class="cv-activity-tags">
    <span class="cv-activity-tag">IEEE Membership (2025)</span>
    <span class="cv-activity-tag">IEEE Computer Society Technical Community on Security and Privacy (2025)</span>
    <span class="cv-activity-tag">IACR Regular Membership (2023)</span>
    <span class="cv-activity-tag">IACR Student Membership (2022, 2021, 2020, 2019)</span>
  </div>
</div>



## Location

<div class="cv-location-card">
  <button class="cv-location-lang-toggle" type="button" data-lang-state="en" aria-pressed="false" title="EN / 中文">
    <span class="cv-toggle-thumb" aria-hidden="true">EN</span>
  </button>
  <div class="cv-location-body">
    <div class="cv-location-room cv-lang" data-en="Room 906, Intellectual Property Building" data-zh="知识产权大楼906室">Room 906, Intellectual Property Building</div>
    <div class="cv-location-address cv-lang" data-en="Jinan University (Panyu Campus), No. 855 Xingye Avenue East, Panyu District, Guangzhou, Guangdong 511443, P. R. China" data-zh="中华人民共和国 广东省广州市 番禺区新造镇兴业大道东855号 暨南大学（番禺校区）">Jinan University (Panyu Campus), No. 855 Xingye Avenue East, Panyu District, Guangzhou, Guangdong 511443, P. R. China</div>
  </div>
</div>

<div id="map-container">
<div id="amap-container"></div>
<a href="https://www.amap.com/search?id=B0JBD7XRFY&city=440113&geoobj=113.402929%7C23.011163%7C113.425245%7C23.022489&query_type=IDQ&query=%E6%9A%A8%E5%8D%97%E5%A4%A7%E5%AD%A6%E7%95%AA%E7%A6%87%E6%A0%A1%E5%8C%BA%E7%9F%A5%E8%AF%86%E4%BA%A7%E6%9D%83%E5%A4%A7%E6%A5%BC&zoom=17" class="map-button" target="_blank">View Map</a>
</div>

</div>
