
<!-- # About Me -->

<div id="intro">
  <div class="profile">
    <div class="image">
      <div id="avatar">
        <img v-on="{ mouseenter: mouseEnter, mouseleave: mouseLeave }" @click="todo"
          :src="logo_list[here_logo]">
      </div>
    </div>
    <div class="info">
      <div class="name">
        <span
          @mouseenter="hover_name = true"
          @mouseleave="hover_name = false"
          >{{ hover_name ? "刘 逸" : "Yi Liu" }}</span
        >
      </div>
      <div class="socials">
        <div>
            <a href="https://scholar.google.com.hk/citations?user=pKOcyg0AAAAJ" target="_blank">
              <img src="public/icons/google-scholar.svg" alt="Google Scholar"
              title="Google Scholar" />
            </a>
            <a href="https://github.com/liu-yi" target="_blank">
              <img src="public/icons/github.svg" alt="Github"
              title="Github" />
            </a>
            <a href="https://www.linkedin.com/in/%E9%80%B8-%E5%88%98-363764114" target="_blank">
              <img src="public/icons/linkedin-mono.svg" alt="LinkedIn"
              title="LinkedIn" />
            </a>
            <a href="https://www.zhihu.com/people/imliuyi" target="_blank">
              <img src="public/icons/zhihu.svg" alt="知乎"
              title="知乎" />
            </a>
        </div>
      </div>
      <div class="contact">
        <div class="email" title="Contact me">i@liuyi.pro, liuyi@jnu.edu.cn</div>
      </div>
      <div class="cv">
        <span v-if="display_todo">[</span><a v-if="display_todo" href="#/miscellaneous/todo">Todo</a><span v-if="display_todo">]</span>
        [<a target="_blank" style="font-size: 1em" href="public/cv/YiLIU-CV-en.pdf" title="Download my CV">
          CV
        </a>]
        [<a target="_blank" style="font-size: 1em" href="public/cv/YiLIU-CV-cn.pdf" title="下载我的中文版简历">
          简历
        </a>]
      </div>
    </div>
  </div>
</div>
<script>
  Vue.createApp({
    data: function(){
      return {
        hover_avatar: false,
        hover_name: false,
        logo_list: ["public/img/logo.jpg", "public/img/logo1.jpg", "public/img/logo2.jpg"],
        todo_num : 0,
        display_todo: false
      }
    },
    methods: {
      mouseEnter(event) {
        // console.log(event)
        this.hover_avatar = true;
        this.hover_name = true; 
      },
      mouseLeave(event) {
        // console.log(event)
        this.hover_avatar = false;
        this.hover_name = false; 
      },
      todo(){
        this.todo_num++; 
        console.log(this.$router)
        if(this.todo_num == 5){
          this.display_todo = true
        }
      }
    }, 
    computed: {
      here_logo() {
        if (this.hover_avatar) {
          return 2;
        } else if (this.here) {
          return 1;
        } else {
          return 0;
        }
      },
    },
    beforeCreate(){
      // if (window.matchMedia('(max-device-width: 767px)').matches){
      //   document.body.classList.remove('close')
      // } 
    }
  }).mount('#intro');
</script>

## About Me
I am Yi Liu (刘逸), a lecturer at College of Cyber Security, [Jinan University (JNU)](https://english.jnu.edu.cn/). My research interests are cryptography and network security, in particular: **secure two-party/multi-party computation**, **zero-knowledge proofs**, **timed cryptography**, **blockchain-related applications**, etc.

## Education

- **The University of Hong Kong (HKU)**  <div class="duration">*Sept. 2018 – Feb. 2023*</div>
  - Ph.D. in Cryptography 
  - Joint Ph.D. Programme with SUSTech
  - Supervisor: [Siu-Ming Yiu](https://www.cs.hku.hk/index.php/people/academic-staff/smyiu) (HKU) and [Qi Wang](http://cse.sustech.edu.cn/faculty/~wangqi/) (SUSTech)
  - Thesis: Private Function Evaluation: Improvements and Applications. 
- **Southern University of Science and Technology (SUSTech)** <div class="duration">*Sept. 2014 – July 2018*</div>
  - B.Eng. in Computer Science and Technology
  <!-- - GPA: **3.84/4.00** (Core); **3.70/4.00** (Overall) -->
  - Thesis: An Evaluation System Based on Blockchain and Linkable Ring Signature. 
  <!-- - [[Slides](https://imliuyi.com/ugthesis_slide.pdf)] -->
    - Best Thesis Award in the CSE Department, SUSTech.


## Publications

<div class="publist">

- **Towards Practical Homomorphic Time-Lock Puzzles: Applicability and Verifiability** <span class="pubtag">[:link:](https://link.springer.com/chapter/10.1007/978-3-031-17140-6_21)</span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 27th European Symposium on Research in Computer Security. **ESORICS 2022**. <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2022/585" target="_blank">ePrint</a></span>

    Copenhagen, Denmark. Sept. 2022.

- **Making Private Function Evaluation Safer, Faster, and Simpler** <span class="pubtag">[:link:](https://link.springer.com/chapter/10.1007/978-3-030-97121-2_13)<span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 25th International Conference on Practice and Theory of Public-Key Cryptography. **PKC 2022**. <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2021/1682" target="_blank">ePrint</a> <a class="btn btn-outline-primary" href="https://www.youtube.com/watch?v=Pv8zVTxacr0" target="_blank">Video</a></span>

    Virtual. March 2022.  

- **Improved Zero-Knowledge Argument of Encrypted Extended Permutation** <span class="pubtag">[:link:](https://link.springer.com/chapter/10.1007/978-3-030-88323-2_15)</span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 17th International Conference on International Conference on Information Security and Cryptology. **Inscrypt 2021**. <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2021/1430" target="_blank">ePrint</a></span>

    Virtual. Aug. 2021. 
    
- **Blind Polynomial Evaluation and Data Trading** <span class="pubtag">[:link:](https://link.springer.com/chapter/10.1007/978-3-030-78372-3_5)</span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 19th International Conference on Applied Cryptography and Network Security. **ACNS 2021**. <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2021/413" target="_blank">ePrint</a></span>

    Virtual. June 2021. 

- **An Improvement of Multi-Exponentiation with Encrypted Bases Argument: Smaller and Faster** <span class="pubtag">[:link:](https://link.springer.com/chapter/10.1007/978-3-030-71852-7_27)</span>
  
    <u>**Yi Liu**</u>, Qi Wang, Siu-Ming Yiu 

    The 16th International Conference on International Conference on Information Security and Cryptology. **Inscrypt 2020**. <span class="pubtag"><a class="btn btn-outline-primary" href="https://eprint.iacr.org/2020/567" target="_blank">ePrint</a> </span>

    Guangzhou, China. Dec. 2020. 

## Manuscripts

- **An E-voting Protocol Based on Blockchain**
  
  <u>**Yi Liu**</u>, Qi Wang

  Manuscript, 2017. <a class="pubtag btn btn-outline-primary" href="https://eprint.iacr.org/2017/1043" target="_blank">ePrint</a>

</div>

## Experience

- **Teaching Assistant**
  - COMP2119: Introduction to Data Structures and Algorithms (HKU Fall 2021)
  - CS403: Cryptography and Network Security (SUSTech Fall 2019, Fall 2020)
  - COMP7904: Information Security: Attacks and Defense (HKU Spring 2019)
  - CS304: Software Engineering (SUSTech Spring 2017)
  - CS201: Discrete Mathematics (SUSTech Fall 2016) 
  - CS302: Operating System (SUSTech Spring 2016)

- **Research Assistant**
  - CoCrypto Lab (Adviser: Qi Wang) <div class="duration">*Sept. 2016 – Aug. 2018*</div>
  - SUSTech Innovation Center for Data Science (Adviser: Rusong Zheng) <div class="duration">*July 2017 – Aug. 2017*</div>
  - UAV and Sensor Network Lab (Adviser: Qi Hao) <div class="duration">*July 2015 – Sept. 2016*</div>

<!-- ## Awards & Honors
- **Best Thesis Award** Department of Computer Science and Engineering of SUSTech **2018**
- **SUSTech Outstanding Student Scholarship** (Third Prize) **2017**
- **SUSTech Outstanding Student Scholarship** (Second Prize) **2016**
- **College Student Start-Up Scholarship** **2014 – 2018** -->

<!-- ## Skills
C/C++, Python, LaTeX, Java, HTML/CSS, JavaScript -->



<style>
.markdown-section p, .markdown-section li{
    margin: 0.4em 0 0.4em 0;
}
.markdown-section ul {
    margin: 0.6em 0 0.6em 0;
}
.markdown-section h2 {
    margin: 1.5rem 0 1rem;
    padding: 0;
}
.duration {
  float: right;
}

/* #about-me {
  display: none
} */
.profile{
    display: flex;
    flex-direction: row; 
    align-items: stretch;
}
.profile .image{
    max-width: 180px;
    padding: 2px; 
    /* border: 1px solid #f2f3f3; */
}
.profile .image img{
    border-radius: 50%;
}
.profile .info{
    display: flex; 
    flex: 1 1;
    flex-direction: column; 
    padding-left: 2rem; 

}
.profile .info .name{
    font-size: 2.5rem; 
    padding-bottom: 8px;
    /* font-weight: 600;  */
}
.profile .info .socials{
    display: flex; 
    flex-direction: row; 

}
.profile .info .socials img{
    width: 1.3rem; 
    margin: 0 0.6rem 0 0;
    cursor: pointer; 
}

.profile .info .contact .email{
    font-family: Courier New, Courier, monospace; 
}


@media (max-width: 480px){
  .profile .image{
        max-width: 150px
    }
  .profile .info .name{
    font-size: 1.8rem; 
    /* font-weight: 600;  */
    }
  .profile .info .socials img{
    width: 1rem; 
    margin: 0 0.6rem 0 0;
    cursor: pointer; 
  }
  .profile .info .contact .email{
    font-size: 0.8rem; 
  }
  .profile .info .cv{
    font-size: 0.9rem 
  }
  .duration {
    float: none;
  }
}
body[data-page="docs/cv.md"] .sidebar,
body[data-page="docs/cv.md"] .sidebar-toggle {
  display: none !important;
}

body[data-page="docs/cv.md"] .content {
  margin-left: 0px !important;
}

.publist .pubtag{
  opacity: 0.0;
}

.publist:hover .pubtag{
  opacity: 1.0;
}

.pubtag{
  transition: all 200ms, opacity 300ms;
}

</style>