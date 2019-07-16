class MyClass {
   int x = 0;
  

   int myInlineMethod()
   {
        auto str = "hello";
        int y = 5 + x;

         auto obj = new MyClass();
         int z = obj->myInlineMethod();
         obj->myOtherThing(z);

         MyClass myClass2;

         MyClass myClass3 = MyClass();

	      return y;
   }
   

   void myOtherThing(int param);
   
   static int inlineStatic()
   {
   }

   static int staticMethod();
};

void MyClass::myOtherThing(int param)
{
   // the otherThing
   int z = 44;
}

void MyClass::staticMethod()
{
   
}


