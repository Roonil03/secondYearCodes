# Lab exercises:
1.	Write a java program to store student record of college named “MIT”. Class Student_Detail should contain name, id, college_name as its members.<br>display_details() method should display the details of the students.

2.	Write a counter program to count the number of objects created.

3.	Write a java program to illustrate autoboxing and unboxing by considering all data types. 

# Additional Exercises:
1)	Write output of the following and analyze the code.
- class Example1{<br>
  //Static class<br>
  static class X{<br>
      static String str="Inside Class X";<br>
  }<br>
  public static void main(String args[])<br>
  {<br>
      X.str="Inside Class Example1";<br>
      System.out.println("String stored in str is- "+ X.str);<br>
  }<br>
}<br>

- class Example2{<br>
   int num;<br>
   //Static class<br>
   static class X{<br>
      static String str="Inside Class X";<br>
      num=99;<br>
   }<br>
   public static void main(String args[])<br>
   {<br>
      Example2.X obj = new Example2.X();<br>
      System.out.println("Value of num="+obj.str);<br>
   }<br>
}<br>

- class Example3{<br>
   static int num;<br>
   static String mystr;<br>
   static{<br>
      num = 97;<br>
      mystr = "Static keyword in Java";<br>
   }<br>
   public static void main(String args[])<br>
   {<br>
      System.out.println("Value of num="+num);<br>
      System.out.println("Value of mystr="+mystr);<br>
   }<br>
}<br>

- class Example4{<br>
   static int num;<br>
   static String mystr;<br>
   //First Static block<br>
   static{<br>
      System.out.println("Static Block 1");<br>
      num = 68;<br>
      mystr = "Block1";<br>
  } <br>
  //Second static block<br>
  static{<br>
      System.out.println("Static Block 2");<br>
      num = 98;<br>
      mystr = "Block2";<br>
  }<br>
  public static void main(String args[])<br>
  {<br>
      System.out.println("Value of num="+num);<br>
      System.out.println("Value of mystr="+mystr);<br>
   }<br>
}<br>


- class Example5{<br>
   static int i;<br>
   static String s;<br>
   public static void main(String args[]) //Its a Static Method<br>
   {<br>
       Example5 obj=new Example5();<br>
       //Non Static variables accessed using object obj<br>
       System.out.println("i:"+obj.i);<br>
       System.out.println("s:"+obj.s);<br>
   }<br>
}<br>

- class Example6{ <br>
  static int i;<br>
  static String s;<br>
  //Static method<br>
  static void display()<br>
  {<br>
     //Its a Static method<br>
     Example6 obj1=new Example6();<br>
     System.out.println("i:"+obj1.i);<br>
     System.out.println("i:"+obj1.i);<br>
  }<br>
<br>
  void funcn()<br>
  {<br>
//Static method called in non-static method<br>
      display();<br>
  }<br>
  public static void main(String args[]) //Its a Static Method<br>
  {<br>
      //Static method called in another static method<br>
      display();<br>
   }<br>
}<br>





