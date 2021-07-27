## An anecdote
<p>&emsp; Though I would like to strictly mention technical details of the project here, I feel, for me this project is just incomplete without an anectode I would like to add.</p>
<p>Those who would like to skip can go here (for manual control details) or here (for autonomous control details) directly.</p>
<p> &emsp; In the 1st semester of college I won in some very easy(not for a novice like me at that time though) technical competitions as any fresher, where I felt, kind of a reconnection with the maker in me. And through those competitions I found this great student club at Lovely Professional University -LPU, called Robotics and Intelligent Systems Community <a href="https://www.facebook.com/RISC.LPU/"> <b>RISC-LPU</b></a>, whose motto says <b>"Learn Implement Share"</b>. In this club I found greatly motivated and enthusiastic students who were going an extra-mile to implement their domain knowledge and at the same time organising workshops to share their experience. Our mentor and founder of RISC-LPU, Asst Prof. Bikash Kant sir, motivated me to take up a project on Robot Manipulator which was'nt explored by the club that time. </p>

<p> &emsp; The culture of the club was to self-learn areas, the club members had not explored, either seeking guidance from the faculty or the internet. Being a student  in 2nd semester and having no connections what-so-ever, it came to me that internet would be the ideal source to learn from. In that course of time I learnt a lot about robotics and robot manipulators. I spent almost all the free time in the club learning about them. Our mentor asked us to start designing a basic manual manipulator arm, because as he belived in 'learning by doing'. With the limited knowledge I had at that time, first I wanted to design something with which I can control the manipulator using an XBox controller I had at that time. So, I started to implement the project in LabVIEW, beacuse it can be interface with both Arduino (we used it as servo controller) and my XBox controller.</p>

<p> &emsp; Nothing felt more cool and interesting than designing a full control panel GUI using LabVIEW at that time. Later I implemented fully autonomous Robot Manipulator, solving the inverse kinematic equations with the basic trignometry I learnt during high school, but not DH Parameters (I learnt about them later). Enough of anecdotes now I think, let me do some technical now. </p>

## Technical details
A [friend](https://www.linkedin.com/in/vinaykumarreddykomma/) of mine later designed this 3D 3R-manipulator for an automatic soil mapping project, which use the same skeleton as the first arm design in the club. So for easier understanding I am showing it here: <br> <br>
![20210727_130156](https://user-images.githubusercontent.com/49190581/127200899-f5317628-6345-4f21-9465-e68cfa2b8640.gif)

### Manual Control using LabVIEW & XBox
<p>The arm has three revolute joints (excluding end-effector). So, three servo motors with adequate torque had been used as actuators.</p>
Also the keys of XBox are as below:

![image](https://user-images.githubusercontent.com/49190581/127202916-da942dde-f313-4e12-8a2a-4eb488e4f7c2.png)

<p>Keys 14, 16 are analog keys whose output range from `- 32,000 to 32,000` and all the other keys were boolean.</p>
  
![image](https://user-images.githubusercontent.com/49190581/127184973-cc0a5b1d-22e9-42f1-b72b-733f363ba98d.png)

![image](https://user-images.githubusercontent.com/49190581/127190143-81cf5fea-1d30-4465-9fd8-31c8f6327ec4.png)


**Content Loading !!**
