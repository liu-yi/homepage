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
            <a target="_blank" href="public/cv/YiLIU-CV-en.pdf">CV</a><span class="divider-tight">·</span><a target="_blank" href="public/cv/YiLIU-CV-cn.pdf">简历</a><span class="divider-wide">|</span><a href="#/for-students/" class="recruit-link">招生<span class="recruit-dot"></span></a>
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

</br>

<div class="student-card">
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
    <p>For more information, see <a href="#/for-students/">Information For Prospective Students</a>. If you are interested, feel free to reach out via email!</p>
  </div>
</div> 


## About Me
I am Yi Liu (刘逸), a lecturer at [College of Cyber Security](https://cybsec.jnu.edu.cn/), [Jinan University (JNU)](https://english.jnu.edu.cn/). My research interests broadly cover cryptography, computer security and privacy. Recently, I've been working on **secure multi-party computation**, **zero-knowledge proof**, **timed cryptography**, **blockchain-related applications**, etc.



## Education

- **The University of Hong Kong (HKU)**  <div class="duration">*Sept. 2018 – Feb. 2023*</div>
  - Ph.D. in Cryptography 
  - Joint Ph.D. Programme with SUSTech
  - Supervisor: [Siu-Ming Yiu](https://www.cs.hku.hk/index.php/people/academic-staff/smyiu) (HKU) and [Qi Wang](https://dake98.github.io) (SUSTech)
  - Thesis: Private Function Evaluation: Improvements and Applications <span class="pubtag"><a class="emoji" href="https://hub.hku.hk/handle/10722/327638" target="_blank">:link:</a></span>
- **Southern University of Science and Technology (SUSTech)** <div class="duration">*Sept. 2014 – July 2018*</div>
  - B.Eng. in Computer Science and Technology
  - Thesis: An Evaluation System Based on Blockchain and Linkable Ring Signature
    - Best Thesis Award in the CSE Department, SUSTech

## Research Projects
- <span title="新型安全多方计算协议设计研究">**Research on the Design of New Secure Multi-Party Computation Protocols**</span> <div class="duration">*2025 – 2026*</div>
  - <span title="项目负责人">Principal Investigator</span>
  - Supported by the <span title="广州市基础与应用基础研究专题（青年博士“启航”项目）">Guangzhou Municipal Fundamental and Applied Basic Research Special Topic Young Doctoral “Sail” Project</span> (Grant No. 2025A04J2146). 
- <span title="新型安全模型中的安全多方计算协议设计">**Design of Secure Multi-Party Computation Protocols in New Security Models**</span> <div class="duration">*2024 – 2026*</div>
  - <span title="项目负责人">Principal Investigator</span>
  - Supported by the <span title="国家自然科学基金青年科学基金项目">Young Scientists Fund of the National Natural Science Foundation of China</span> (Grant No. 62302194). 

## Selected Publications

<div class="publist">

<span><a class="btn btn-outline-primary" style="font-size: 17px; width: 100%; padding: 2px" href="#/publications/?id=main">Full List of Publications</a></span>


- **Zero-Knowledge Protocols with PVC Security: Striking the Balance between Security and Efficiency** <span class="pubtag"><a class="emoji" href="https://doi.org/10.1007/978-981-95-3540-8_8" target="_blank">:link:</a></span>

    <u>**Yi Liu**</u>, Yipeng Song, Anjia Yang, Junzuo Lai

    The 27th International Conference on Information and Communications Security (**ICICS 2025**). <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2025/2146" target="_blank">ePrint</a></span>
    
    Nanjing, China. Oct. 2025.


- **Highly Efficient Actively Secure Two-Party Computation with One-Bit Advantage Bound** <span class="pubtag"><a class="emoji" href="https://doi.ieeecomputersociety.org/10.1109/SP61157.2025.00183" target="_blank">:link:</a></span>

    <u>**Yi Liu**</u>, Junzuo Lai, Peng Yang, Anjia Yang, Qi Wang, Siu-Ming Yiu, Jian Weng

    The 46th IEEE Symposium on Security and Privacy (**S&P 2025**). <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2025/614" target="_blank">ePrint</a></span> <span class="pubtag"><a class="btn btn-outline-primary" href="public/pdf/Oakland25.pdf" target="_blank">Poster</a></span>
    
    San Francisco, USA. May 2025.

- **Robust Publicly Verifiable Covert Security: Limited Information Leakage and Guaranteed Correctness with Low Overhead** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-981-99-8721-4_9" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Junzuo Lai, Qi Wang, Xianrui Qin, Anjia Yang, Jian Weng 

    The 29th International Conference on the Theory and Application of Cryptology and Information Security (**ASIACRYPT 2023**). <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2023/1392" target="_blank">ePrint</a></span>

    Guangzhou, China. Dec. 2023.

- **Towards Practical Homomorphic Time-Lock Puzzles: Applicability and Verifiability** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-031-17140-6_21" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 27th European Symposium on Research in Computer Security (**ESORICS 2022**). <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2022/585" target="_blank">ePrint</a></span>

    Copenhagen, Denmark. Sept. 2022.

- **Making Private Function Evaluation Safer, Faster, and Simpler** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-030-97121-2_13" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 25th International Conference on Practice and Theory of Public-Key Cryptography (**PKC 2022**). <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2021/1682" target="_blank">ePrint</a> <a class="btn btn-outline-primary" href="https://www.youtube.com/watch?v=Pv8zVTxacr0" target="_blank">Video</a></span>

    Virtual. March 2022.  

- **Improved Zero-Knowledge Argument of Encrypted Extended Permutation** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-030-88323-2_15" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 17th International Conference on International Conference on Information Security and Cryptology (**Inscrypt 2021**). <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2021/1430" target="_blank">ePrint</a></span>

    Virtual. Aug. 2021. 
    
- **Blind Polynomial Evaluation and Data Trading** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-030-78372-3_5" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 19th International Conference on Applied Cryptography and Network Security (**ACNS 2021**). <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2021/413" target="_blank">ePrint</a></span>

    Virtual. June 2021. 

- **An Improvement of Multi-Exponentiation with Encrypted Bases Argument: Smaller and Faster** <span class="pubtag"><a class="emoji" href="https://link.springer.com/chapter/10.1007/978-3-030-71852-7_27" target="_blank">:link:</a></span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 16th International Conference on International Conference on Information Security and Cryptology (**Inscrypt 2020**). <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2020/567" target="_blank">ePrint</a> </span>

    Guangzhou, China. Dec. 2020. 



</div>


## Teaching
- **Undergraduate Courses**
  - C++ Programming (Fall 2025, Fall 2024, Fall 2023)
  - Public-Key Cryptography (Spring 2025)

- **Graduate Courses**
  - Advanced Cryptography (Fall 2025, Fall 2024, Fall 2023)


## Students

- **Postgraduate Students**
  - Yulong Du (Master, since 2025)
  - Cuiying Zhao (Master, since 2025)
  - Yunqi He (Master, since 2024)
  - Yipeng Song (Master, since 2023)

- **Undergraduate Students**
  - Tao Jiang (B.Eng. 2026)
  - Junsong He (B.Eng. 2026)
  - Yuanhao Zhuang (B.Eng. 2026) 
  - Jiquan Yang (B.Eng. 2025)
  - Junjie Li (B.Eng. 2024; first employment: Tencent)
  - Wanqing Li (B.Eng. 2024; first employment: Midea)


## Professional Activities
- **Journal Reviewers**
  - IEEE Transactions on Dependable and Secure Computing
  - IEEE Transactions on Industrial Informatics
  - International Journal of Information Security 
  - Web Intelligence
  - Frontiers of Computer Science
- **Conference Reviewer**
  - IEEE BSC@QRS (2022, 2021, 2020)
- **Membership**
  - IEEE Membership (2025)
  - IEEE Computer Society Technical Community on Security and Privacy (2025)
  - IACR Regular Membership (2023)
  - IACR Student Membership (2022, 2021, 2020, 2019)



## Location

<div class="address-wrapper">
  <div class="address-container" id="address-en" data-lang="en">
    <span class="room-info">Room 906, Intellectual Property Building</span>
    Jinan University (Panyu Campus), No. 855 Xingye Avenue East, Panyu District, Guangzhou, Guangdong 511443, P. R. China  
    <br>
  </div>
  <div class="address-container" id="address-cn" data-lang="cn" style="display: none;">
    <span class="room-info">知识产权大楼906室</span>
    中华人民共和国 广东省广州市 番禺区新造镇兴业大道东855号 暨南大学（番禺校区）
    <br>
  </div>
</div>

<div id="map-container">
<div id="amap-container"></div>
<a href="https://www.amap.com/search?id=B0JBD7XRFY&city=440113&geoobj=113.402929%7C23.011163%7C113.425245%7C23.022489&query_type=IDQ&query=%E6%9A%A8%E5%8D%97%E5%A4%A7%E5%AD%A6%E7%95%AA%E7%A6%87%E6%A0%A1%E5%8C%BA%E7%9F%A5%E8%AF%86%E4%BA%A7%E6%9D%83%E5%A4%A7%E6%A5%BC&zoom=17" class="map-button" target="_blank">View Map</a>
</div>

</div>
