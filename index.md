## A Personal anecdote

<p align="justify">
  &emsp; Though I would like to strictly mention technical details of the project here, I feel, for me this project is just incomplete without an anectode I would like to add.</p>
  
<p align="justify">
  Those who would like to skip can go <a href="#manual_code"><u><b>here</b></u></a> (for manual control details) or <a href="#auto_code"><u><b>here</b></u></a> (for autonomous control details) directly.
</p>
  
<p align="justify">
  &emsp; In the 1st semester of college I won in some very easy(not for a novice like me at that time though) technical competitions as any fresher, where I felt, kind of a reconnection with the maker in me. And through those competitions I found this great student club at Lovely Professional University -LPU, called Robotics and Intelligent Systems Community <a href="https://www.facebook.com/RISC.LPU/" target="_blank" rel="noreferrer noopener"> <b>RISC-LPU</b></a>, whose motto says <b>"Learn Implement Share"</b>. In this club I found greatly motivated and enthusiastic students who were going an extra-mile to implement their domain knowledge and at the same time organising workshops to share their experience. Our mentor and founder of RISC-LPU, Asst Prof. Bikash Kant sir, motivated me to take up a project on Robot Manipulator which was'nt explored by the club that time. 
</p>

<p align="justify"> 
  &emsp; The culture of the club was to self-learn areas, the club members had not explored, either seeking guidance from the faculty or the internet. Being a student  in 2nd semester and having no connections what-so-ever, it came to me that internet would be the ideal source to learn from. In that course of time I learnt a lot about robotics and robot manipulators. I spent almost all the free time in the club learning about them. Our mentor asked us to start designing a basic manual manipulator arm, because as he belived in 'learning by doing'. With the limited knowledge I had at that time, first I wanted to design something with which I can control the manipulator using an XBox controller I had at that time. So, I started to implement the project in LabVIEW, beacuse it can be interface with both Arduino (we used it as servo controller) and my XBox controller.
</p>

<p align="justify"> &emsp; Nothing felt more cool and interesting than designing a full control panel GUI using LabVIEW at that time. Later I implemented fully autonomous Robot Manipulator, solving the inverse kinematic equations with the basic trignometry I learnt during high school, but not DH Parameters (I learnt about them later). Enough of anecdotes now I think, let me do some technical now. </p>

## Technical details
A <a href="https://www.linkedin.com/in/vinaykumarreddykomma/" target="_blank" rel="noreferrer noopener">friend</a> of mine later designed this 3D 3R-manipulator for an automatic soil mapping project, which use the same skeleton as the first arm design in the club. So for easier understanding I am showing it here: <br> <br>
  
![20210727_130156](https://user-images.githubusercontent.com/49190581/127200899-f5317628-6345-4f21-9465-e68cfa2b8640.gif)

<h3>
<a id="manual_code">Manual Control using LabVIEW & XBox</a>
  </h3>
  
<p align="justify">The arm has three revolute joints (excluding end-effector). So, three servo motors with adequate torque had been used as actuators.</p>
Also the keys of XBox are as below:

<img src = "https://user-images.githubusercontent.com/49190581/127202916-da942dde-f313-4e12-8a2a-4eb488e4f7c2.png" alt="xbox layout" width="400" height="auto">

<p align="justify"> Here keys 14, 16 are analog keys whose output range from `- 32,000 to 32,000` and all the other keys are just boolean.</p>

#### LabVIEW Control Panel
  
![image](https://user-images.githubusercontent.com/49190581/127184973-cc0a5b1d-22e9-42f1-b72b-733f363ba98d.png) <!--LabVIEW CP-->

#### LabVIEW Block Logic

<p align="justify"> Because of all the wiring and absence of abstraction in blocks, it might seem a little clumsy, but the implementation is pretty straignt forward. For all the boolean inputs an `adder` or a `substracter` is connected and pressing a boolean input increases or decreases the servo angle. `if - else` containers have been used to clamp the variables from incrementing beyond joint angle limit. Whereas for analog inputs, use of a down-scaler  has been made to map the analog input to range of joint angles. Also one servo we used has just a speed control, so double loop logic has been used in such case.</p>

![image](https://user-images.githubusercontent.com/49190581/127190143-81cf5fea-1d30-4465-9fd8-31c8f6327ec4.png) <!--LabVIEW block diagram-->

### Autonomous Implementation

To skip theory head to code <a href="auto code">click here</a>.

<p align="justify"> Here I'll be showing two ways of implementing inverse kinematic(IK) sollution.</p>

  1. Mathematical IK sollution, which is easy to solve for upto 4-DOF 4R manipulators.
  2. A numerical method of IK sollution implemented using <a href="https://www.roboticslibrary.org/" target="_blank" rel="noreferrer noopener"> friend </a> API's.
 
 <h5>Simply put:</h5>
 <h6> Forward kinematics</h6>
<p align="justify">GIVEN THE TWIST AND JOINT ANGLES WE DETERMINE THE POSITION OF THE END EFFECTOR </p>

<h6> Inverse kinematics</h6>
<p align="justify"> GIVEN THE POSITION OF THE END EFFECTOR WE DETERMINE THE TWIST AND JOINT ANGLES </p>

#### Conventions

<img src="https://user-images.githubusercontent.com/49190581/127517308-4929cfc2-fec1-490e-bfd8-4422116f8538.png" alt="Top View" width="450" height="auto">

<br>While solving any problem in cartesian space we assume some sign conventions (relative to something),<br>
In our case let us assume,
a. Reference axis is the horizontal axis ||el to ground.
b. Angle measured anticlockwise away from reference axis is positive.
c. Angle measured clockwise away from reference axis is negative.

<img src="https://user-images.githubusercontent.com/49190581/127517782-340d529d-5fde-4c50-9298-224a1618646b.png" alt="img2" width="350" height="auto">

<p align="justify">
Here,
 <br> a) (X,Y,Z) is the point end effector needs to reach
 <br> b) (X3,Y3,Z3) is the end point of link 3 as shown
</p>

<p align="justify">
Our aim is to find twist angles i.e. angle of the link with respect to its previous link’s reference axis.
<br>In the figure the twist angles are, 1   ,   2   ,   3   . 
  </p>
 
As you can see,
<br> a) θ2 = α + β
<br> b) Θ3 = 180 – (θ2 + γ)

<p align="justify">
  IF THERE ARE ONLY TWO LINKS WITH REVOLUTE JOINTS AND ONLY ONE DEGREE OF FREEDOM THERE ARE ONLY TWO SOLLUTIONS
 </p>
  
  <img src="https://user-images.githubusercontent.com/49190581/127520263-07ce1e9c-dac4-4c38-8faf-84ca7656e855.png" alt="img5" width="500" height="auto">

<p>SOL2 IS MIRROR IMAGE OF SOL1 </p>

<img src="https://user-images.githubusercontent.com/49190581/127523894-56ab111b-cbff-4b3e-9208-6010e1ed2486.png" alt="img6" width="350" height="auto">

<p>
 <b> WHEN WE HAVE MORE THAN TWO LINKS OR TWO LINKS WITH MORE THAN ONE DEGREE OF FREEDOM, THEN THE SOLLUTIONS WILL BE INFINITE.
  </p>
  
 <h5>Process Flow of Program</h5>
 
 <img src="https://user-images.githubusercontent.com/49190581/127529867-4aa2d110-a006-49b0-a596-17963ee1bc98.png" alt="img7" width="1000" height="auto">

 <br> <img src="https://user-images.githubusercontent.com/49190581/127524838-524424b9-4e41-4f97-b2ea-13e1194c85aa.png" alt="img8" width="450" height="auto"> &emsp; <img src="https://user-images.githubusercontent.com/49190581/127530483-407c4ffc-838d-4dc2-a50f-e90ef70751a1.png" alt="img9" width="300" height="auto">
 
 <p>
  POINT OF END EFFECTOR SHOULD BE (X,Y,Z) = (LpCOS θ1 , LpSIN θ1 , Z)
  </p>
  
  <p>
  X3  = X – L4(COSθ4)(COSθ1) 
  <br> &emsp; = LpCOSθ1 – L4(COSθ4)(COSθ1) 
<br> Y3 = Y – L4(COSθ4)(SINθ1)   
<br> &emsp; = LpSINθ1 – L4(COSθ4)(SINθ1)
<br> Z3 = Z – L4SINθ4
  </p>

<img src="https://user-images.githubusercontent.com/49190581/127531063-0e29c02f-d614-4849-beaf-6ae6c273469c.png" alt="img10" width="350" height="auto">

<br> <img src="https://user-images.githubusercontent.com/49190581/127531265-7a9884df-1b65-4240-a687-7e93b9f11fcb.png" alt="img10 1" width="350" height="auto"> &emsp; <img src="https://user-images.githubusercontent.com/49190581/127531399-3f711630-721a-4ba1-b307-b54508c6d492.png" alt="img10" width="200" height="auto">

<br> <img src="https://user-images.githubusercontent.com/49190581/127531970-53866ff1-2b97-4a40-8b6f-2f7b75fc1b0a.png" alt="img10 3" width="350" height="auto"> &emsp; <img src="https://user-images.githubusercontent.com/49190581/127531984-2451acaf-c641-4798-a0f2-bf0500ae9979.png" alt="img10" width="200" height="auto">

<p> Angle of the end effector can be determined using camera, angle of welding, angle of drilling etc accordingly. But in this case we can hardcode or define the angle in the program because we can always lift block at 0 degree with respect to horizontal cartesian plane.
</p>

<p>Now let us implement above sollution in C++.</p>
<h3>
  <a id="auto_code">
    C++ Implementation
    </a>
  </h3>
  
  
**Content Loading !!**
