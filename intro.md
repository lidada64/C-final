# ISSUE
## **Database**

### Good Examples

1. **Healthcare Systems**: Safely store and quickly access patient records.  
    **医疗系统**：安全存储并快速访问患者记录。
    
2. **Search Engines**: Organize and retrieve web information efficiently.  
    **搜索引擎**：高效组织和检索网络信息。
    
3. **Social Media**: Manage large user data to improve experience.  
    **社交媒体**：管理大量用户数据以提升体验。
    

### Bad Examples

1. **Data Breaches**: Weak security causes personal data leaks.  
    **数据泄露**：安全性差导致个人信息泄露。
    
2. ==**Surveillance== Abuse**: Misuse of databases to track people unfairly.  
    **监控滥用**：滥用数据库不公正地追踪个人。
    
3. **Information Cocoons**: Big data traps people in similar information circles.  
    **信息茧房**：大数据让人困在相似的信息圈里。
    

---

## **Artificial Intelligence**

### Good Examples

1. **Process Automation**: Simplifies repetitive tasks to save time.  
    **流程自动化**：简化重复性任务以节省时间。
    
2. **Self-Driving Cars**: AI helps cars drive and make decisions.  
    **自动驾驶汽车**：AI帮助汽车驾驶并做出决策。
    
3. **Learning Platforms**: AI tailors education to student needs.  
    **学习平台**：AI根据学生需求定制教育内容。
    

### Bad Examples

1. **Fake Videos (Deepfakes)**: Misleading content harms trust.  
    **假视频（Deepfake）**：虚假内容破坏信任。
    
2. **Too Much Automation**: Overuse reduces human skills and creativity.  
    **过度自动化**：过度使用降低人类技能和创造力。
    
3. **Privacy Risks**: AI tracking invades personal space.  
    **隐私风险**：AI追踪侵犯个人空间。
    

---

## **Computer Graphics & Entertainment**

### Good Examples

1. **Movies**: Realistic effects make stories more engaging.  
    **电影**：真实特效让故事更吸引人。
    
2. **3D Design**: Helps show building ideas before construction.  
    **3D设计**：在施工前展示建筑想法。
    
3. **Digital Art**: Tools like _Blender_ help create amazing visuals.  
    **数字艺术**：使用如_Blender_等工具创造惊人视觉效果。
    

### Bad Examples

1. **Harmful Deepfakes**: Graphics used to spread false or harmful content.  
    **有害Deepfake**：图形技术被用来传播虚假或有害内容。
    
2. **Addictive Games**: Graphics make games hard to stop, affecting health.  
    **令人上瘾的游戏**：画面让游戏难以停止，影响健康。
    
3. **Cultural Loss**: Overuse of Western styles weakens local culture.  
    **文化流失**：过度使用西方风格削弱本地文化。
    

---

# Tutorial
## Chap 1
1 ._Using design and developing algorithm as the center task of a computer  scientist, describe the four major studies of computer science._
	**Formal and mathematical properties (theory of computation)**  
		• Studying the behavior of algorithms to determine whether they are correct and efficient  
	**Hardware realizations** 
		• Designing and building computer systems that are able to execute algorithms
	**Linguistic realizations**  
		• Designing programming languages and translating algorithms into these languages so that they can be executed by the hardware  
	**Applications** 
		• Identifying important problems and designing correct and efficient software packages to solve these problems
		
2._Explain the categories of operations for constructing algorithms._
	Sequential/Basic operations 顺序
	 Conditional operations 条件
	 Iterative operations 重复
3._Describe the important characteristics of algorithms._
	 **1.Well ordered and unambiguous operation**
		* must be in correct order for computer to execute it.
		* A primitive operation that can be understood and carried out directly by the computing agent  without needing to be further simplified or explained
	 **2.Effectively computable**
		* It must also be doable by the computing agent. 
		* Computational process exists that allows computing agent to complete that operation  successfully
	 **3.Problem Solving**
		An algorithm must produce a result that is observable to a user
	 **4.Termination - halts in a finite amount of time**
		The result of the algorithm must be produced after the execution of a finite number of  operations


## Chap 2A
Sound convertion
	*Explain the characterizes of sound waves.*
		 – Amplitude: height of the wave at a moment in time  
		 – Period: length of time until wave pattern repeats  
		 – Frequency: number of cycles per unit time
	*Describe sound digitization and the criteria of maintaining high quality  sound during the process.*
		**Digitize**: to convert to a digital form  
		**Sampling**: record sound wave values at fixed, discrete intervals 
		 • To reproduce sound, approximate using samples  
		 • Quality is determined by 
		  – Sampling rate: number of samples per second 
		     More samples ► more accurate waveform 
		   – Bit depth: number of bits per sample 
		     More bits ► more accurate amplitude
		**Data compression** : storing data in a reduced-size form to save space/time 
		 – Lossless: data can be perfectly restored  
		 – Lossy: data cannot be perfectly restored

## Chap 2B
只有多选

## Chap 3
大题集中区
*1.Describe the register cache and DRAM*
	1.**Registers** are the fastest and smallest type of memory 
		– located within the central processing unit (CPU) 
		– directly accessible by CPU  
		– hold data, instructions, and control information that the CPU needs to  perform operations 
		– store small amounts of data that are frequently accessed by the CPU
	2.**Cache memory** is using static RAM (SRAM)
		– Built into or on the CPU for fast accessing.  
		– Using 6 transistor to hold 1 bit of data to maintain data for instant  accessing without reenergizing/refreshing like DRAM. 
		– faster but more expensive and bigger (for same capacity) than DRAMs
		***Cache hit rate: percentage of times values are found in cache***
	3.**DRAM** – Main memory uses DRAM 
		 – Each cell in a dynamic RAM (DRAM) chip contains a transistor and a  capacitor.
		 – The capacitor can store an electrical charge, to represent a 1, or no  charge, to represent a 0.  
		 – Each cell is connected to an address line and a data line. A pulse sent  along an address line turns on the transistors on the line.  
		 – A DRAM storage cell is dynamic, meaning that it needs to be refreshed or  given a new electronic charge every few milliseconds to compensate for  charge leaks from the capacitor.
*2.Descirbe the ALU(Arithmetic Logic Unit)*
	**ALU** is part of the processor  
	– Contains circuits for arithmetic  
		▪ Addition, subtraction, multiplication, and division  
	– Contains circuits for comparison and logic  
		▪ Equality, and, or, not  
	– Contains registers: a special high-speed storage cell that holds the operands  of an arithmetic operation and that, when the operation is complete, holds  its result.  

>	• Data path: how information flows in the ALU  
>		– From registers to circuits  
>		– From circuits back to registers  
>	• Bus: a path for electrical signals

*3.Descirbe the components of CU(Control Unit)*
The control unit contains:  
	**• Program counter (PC) register**: holds the address of the next instruction  
– It is like a “pointer” specifying which address in memory the control unit must go to get the next instruction.  
	**• Instruction register (IR)**: holds the encoding (binary values) of the current instruction 
– The IR holds both the operation code and the address of the data (both needed for the operation)  
	**• Instruction decoder circuit**
– To determine what instruction is in the IR, the operation code of the IR must be decoded using an instruction decoder and signals helper circuits, one per instruction  
	▪ Helpers send addresses to proper circuits 
	▪ Helpers signal ALU, I/O controller, and memory

*4.Describe the Mechine cycle and explain instruction time(I-time) and execution time(E-time)*
	**Machine cycle** – the fundamental operation cycle of the CPU  
	• The control unit 
		 1. fetches from memory the next binary instruction to be executed
		 2. decodes it—the binary instruction is converted to signals that control other parts of the CPU,  
		 3. executes it by issuing the appropriate command to the ALU, memory or I/O devices (depends on the instruction)  
		 4. store the result to memory or register.
	• These steps are repeated over and over until we reach the last instruction in the program.
	 **Instruction time (I-time )**  
		▪ Time taken by the Control Unit to get an instruction from memory and to load it to the register.  
		▪ Time taken by the CU to decode the instruction and to find out the location of the required data. 
	 **Execution time (E-time )** 
		▪ Time required by the control unit to move data from the memory to the registers in the ALU 
		▪ Time taken by ALU to executes the operation on the data  
		▪ Time taken for CU to store data to the memory/register.

## Chap 4A
 *1.Compare program writing for naked machine and virtual machine.
	 Naked machine  
		 1. Write program in binary (machine  language) 
		 2. Load instructions one by one into  memory  
		 3. Insert start into memory address 0  and push “start” button  
		 4. Read results from memory one by  one, in binary
	 Virtual environment
		 1. Write program using text editor in  high-level programming language  (human understandable). 
		 2. Use an information manager  to save program to folder  
		 3. Use language translator to convert  the program to binary  
		 4. Use scheduler to load and run  program  
		 5. Use I/O system to print results
>Writing program for naked machine is difficult

 *2.Describe machine language and the drawback of machine language.*
	 **machine language** (machine code/object code).
		 1.Is a collection of binary digits or bits that the computer reads and interprets
		 2.It is the only language a computer is capable of understanding
		 3.High level languages must be compiled into machine language before run on computer
		 ***drawback** 
		1.Uses binary
			is primitive to machine but not human
		2.Difficult to create data
		3.It allows only memory addresses in binary
		4.It is difficult to change/edit
		
*3. Explain the benefits of writing programs in assembly language rather than  machine language* 
	***Advantages of assemble language***
		1.Use of symbolic operation codes rather than numric ones
		2.Use of symbolic memory address rather than numric ones
		 3.pseudo-operations that provide useful **user-oriented** services 
	 ***Advantages over machine code***  
		 ▪ Program clarity, readability, and maintainability  
		 ▪ Instructions can be placed at different locations  in memory

*4. Illustrate and describe the translation/loading/execution process of running a  assembly language program.*
	1.Source program (in assembly  language) is translated by the  assembler to Object program (in  machine language)  
	2.Loader places machine language  into memory 
	3. Hardware executes the program  and produce results
>**loader** reads instructions from object files and store them into memory for execution.


## Chap 4B
题少,没有给重点

## Chap 5
*1.Define App(application software)*
>An application, or app, sometimes called application software, consists of  programs designed to make users more productive and/or assist them with  personal tasks

*2.Categories of apps*(根据用途，非重点)
	productivity
	 Graphic and media 
	 personal interest
	 security
	 system management
	 File and storage management
*3.Categories of apps*（根据性质）
	1.Native app – It is an app written for a specific platform and installed on a  computer or mobile device. E.g. Apps for Windows, Apple, Android, etc.
	2.Cloud/web app – It requires browsers and Internet connection, makes used  of software and data that are not stored on users’ computer or mobile  device, with responsive web design to cater for different device sizes.
*4.Categories of apps*(根据形式)
	1.**Retail /commercial software** - Copyrighted software developed, usually by  a commercial company, for sale to others.
	 2.**Custom software** – performs functions specific to a business or industry.
	 3.**Shareware** - Copyrighted software distributed on the honor system;  consumers should either pay for it or uninstall it after the trial period.
	 4.**Freeware** - Copyrighted software that may be used free of charge. Author  retains copyright. May place restrictions on its use. May not be altered or  redistributed without permission .
	 5.**Open source software** - Programs with source code available to the  general public. Other programmers can modify and redistribute the  programs freely.
	 6.**Public domain software** - Software that is not copyrighted. May be used  and even altered without permission. Typically developed by universities  and/or research institutions using government grants.


## Chap 8
全是重点
*1.Explain the CIA Triad*
	1.**Confidentiality**:  
		1.– Preserving authorized restrictions on information access and disclosure, including  means for protecting personal privacy and proprietary information.
		 2.– A loss of confidentiality is the unauthorized disclosure of information.  
	1. **Integrity**:  
		1. – Guarding against improper information modification or destruction, including ensuring  information nonrepudiation and authenticity.
		2. – A loss of integrity is the unauthorized modification or destruction of information.  
	2. **Availability**:  
		1. – Ensuring timely and reliable access to and use of information.  
		2.– A loss of availability is the disruption of access to or use of information or an  information system.

*2.What are white hat hacker, black hat hacker, cracker, script kiddie, cyberextortionist and cyberterrorist?*
	1. **Hacker**  –
		**White hats** are security experts and those who work to help protect  systems from attackers.  – **Black hats** are individuals or groups steal information, money, or do  other immoral, and illegal acts.  
	2. **Cracker** - who accesses a computer or network illegally with the  intention of destroying data, stealing information, or other malicious  action. 
	3. **Script kiddie** - has the same intent as a cracker but does not  have the technical skills and knowledge.
	4. **Cyberextortionist** - someone who demands payment to stop an  attack on an organization’s technology infrastructure.  
	5. **Cyberterrorist** - someone who uses the Internet or network to  destroy or damage computers for political reasons.

*3.Describe cyber-attacks including viruses, worms, Trojan horses, DoS attacks, and phishing* 
	1.**Virus:** program embedded within another program or file, replicates  itself and attacks other files  
	2.**Worm**: program that can send copies of itself to other nodes on the  network 
	3.**Trojan horse**: program that seems beneficial but hides malicious  code within it.
	4.**Denial-of-service (DoS) attack**: many computers try to access the same URL at the same time
	5.**Phishing**: obtain sensitive information by impersonating legitimate sources, such  as credit card numbers, account numbers, and passwords

*4.Explain encryption and decryption*
	1.Encryption 
		 – a process of an algorithm (program) encodes or scrambles information during transmission or storage.  
		– converting data that is readable by humans (plaintext) into encoded characters (ciphertext) to prevent unauthorized access  
	2.Decryption  
		– inverse operations of encryption. 
		 – Decoded/unscrambled by only authorized individuals to read it  – Convert from ciphertext back to plaintext.
*5.Describe the overall process of symmetric and asymmetric (public-key) encryption*
	1.**Symmetric encryption algorithm**  – A secret key shared by the sender and the receiver  – Same key is used to encrypt and decrypt  – Risk during transmitting the secret key. 
	2.**Asymmetric encryption algorithm (public key)**  – Uses two keys: public and private  – Use public key (generally known) to encrypt  – Use private key (known only to receiver) to decrypt
*6.Compare and contrast symmetric and asymmetric encryption based on five key aspects*

| a                                   | Symmetric key enctyption                    | Asymmetric key encryption                                                                   |     |
| ----------------------------------- | ------------------------------------------- | ------------------------------------------------------------------------------------------- | --- |
| 1.Symmetric key vs asymmetric key   | One key                                     | two different keys(public key and private keys)                                             |     |
| 2.Complexity and speed of execution | simple and quickly                          | complex and slower                                                                          |     |
| 3.Length fo keys                    | 128-256                                     | much longer(eg.2048)                                                                        |     |
| 4.Usage                             | Large chunks of data need to be transferred | smaller transcations primary to autherenticate and establish a secure communication channal |     |
| 5.Security                          | low security                                | high security                                                                               |     |
|                                     |                                             |                                                                                             |     |
*7.Describe ways to increase the security of your information.*
	1.Use end-to-end encryption 
	2.Use Strong, Unique Passwords
	3Enable Two-Factor Authentication (2FA)
	4.Be Cautious with Public Wi-Fi and use vpn to protecty personal information
*8.Ways to Secure Yourself While Gaming*
	1.Use Strong, Unique Passwords
	2.Avoid Sharing Personal Information
	3.Be Cautious with Mods and Downloads
	4.Monitor Account Activity
  
  
  
  
  
  
  
  