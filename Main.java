import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Main
{
  public static void main(String[] args) 
  {
    ArrayList<Integer> arrayInt = new ArrayList<Integer>();
    arrayCreate(arrayInt);
    System.out.println("Operations : \n1.Add an Element"+
                                    "\n2.Sort the Array"+
                                    "\n3.Insert an Element"+
                                    "\n4.Remove an Element"+
                                    "\n5.Clear the Array"+
                                    "\n6.Print the Array"+
                                    "\n(Press any letter to exit.)");
    operations(arrayInt);
  }


  public static void arrayCreate(ArrayList<Integer> arrayInt)
  {
    System.out.println("Enter the Elements to be Inserted (Press any letter to exit) : ");
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    try 
    {
      while (n+1 != n)
      {
        arrayInt.add(n);
        System.out.println(arrayInt);
        n = input.nextInt();
      }
    } catch (Exception e)  
      {
        System.out.println("Exited.");
      }
  }

  public static void arrayPrint(ArrayList<Integer> arrayInt)
  {
    System.out.println("Array : "+arrayInt);
  }

  public static void arrayAdd(ArrayList<Integer> arrayInt)
  {
    System.out.println("Enter the element to add : ");
    Scanner addElem = new Scanner(System.in);
    try{
      arrayInt.add(addElem.nextInt());
      arrayPrint(arrayInt);
    }catch (Exception e){
      System.out.println("Enter Numbers only!");
      arrayAdd(arrayInt);
    }

  }

  public static void arraySort(ArrayList<Integer> arrayInt)
  {
    
    try {
      System.out.println("1.Ascending\n2.Descending");
      Scanner sortChoose = new Scanner(System.in);
      if (sortChoose.nextInt()==1){
        Collections.sort(arrayInt);
      }else{
        Collections.sort(arrayInt, Collections.reverseOrder());
      }
    } catch (Exception e) {
      System.out.println("Invalid Option!");
      arraySort(arrayInt);
    }
    arrayPrint(arrayInt);
    System.out.println("Array Sorted Successfully!");
  }

  public static void arrayClear(ArrayList<Integer> arrayInt)
  {
    System.out.println("Array Cleared Successfully.");
    arrayInt.clear();
    return;
  }
  
  public static void arrayInsert(ArrayList<Integer> arrayInt) 
  {
    Scanner index = new Scanner(System.in);
    Scanner elemIns = new Scanner(System.in);
    try {
      System.out.println("Enter the Element to Be Inserted : ");
      int a = elemIns.nextInt();
      System.out.println("Enter the Index of where it should be inserted : ");     
      int b = index.nextInt();
      if (b>arrayInt.size() | arrayInt.size() < 0){
        System.out.println("Enter number within the index range of 0 ~ "+arrayInt.size()+" of the Array.");
        arrayInsert(arrayInt);
      }else{
        arrayInt.add(b, a);
        arrayPrint(arrayInt);
        System.out.println(("Array Inserted Successfully!"));
      }
      } catch (Exception e) {
      System.out.println("Enter Numbers Only!");
      arrayInsert(arrayInt);
    }
  }

  public static void arrayRemove(ArrayList<Integer> arrayInt)
  {
    Scanner index = new Scanner(System.in);
    try {
      System.out.println("Enter the Index of Element to be Deleted : ");     
      int b = index.nextInt();
      if (b>arrayInt.size() && arrayInt.size() < 0){
        System.out.println("Invalid Index.\nCurrent Index Range : 0 ~ "+arrayInt.size());
        arrayRemove(arrayInt);
      }else{
        arrayInt.remove(b);
        arrayPrint(arrayInt);
        System.out.println(("Element removed Successfully!"));
      }
      } catch (Exception e) {
      System.out.println("Enter Numbers Only!");
      arrayRemove(arrayInt);
    }
  }

  public static void operations(ArrayList<Integer> arrayInt)
  {
    Scanner choose = new Scanner(System.in);
    try {
      switch (choose.nextInt()) {
        case 1:
          arrayAdd(arrayInt);
          operations(arrayInt);
        case 2:
          arraySort(arrayInt);
          operations(arrayInt);
        case 3:
          arrayInsert(arrayInt);
          operations(arrayInt);
        case 4:
          arrayRemove(arrayInt);
          operations(arrayInt);
        case 5:
          arrayClear(arrayInt);
          operations(arrayInt);
        case 6:
          arrayPrint(arrayInt);
          operations(arrayInt);

        default:
          System.out.println("Invalid Option!\nChoose from the Given options only!\nIf you want to exit, press any letter..");
          operations(arrayInt);
      }
    } catch (Exception e) {
      System.exit(0);
    }
    
  }
}
