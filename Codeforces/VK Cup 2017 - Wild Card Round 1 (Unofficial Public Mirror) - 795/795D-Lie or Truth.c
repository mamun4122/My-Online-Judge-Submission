using System;
using System.Linq;

public static class Program
{
    public static void Main()
    {
     int [] l = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
  int [] arr = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
  int [] arr1 = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
  bool flag = true;
  l[1]--;
  l[2]--;
  for(int i = 0; i < l[1]; i++){
   if(arr[i] != arr1[i])
    flag = false;
  }
  for(int i = l[2]+1; i < l[0]; i++)
   if(arr[i] != arr1[i])
    flag = false;
  int [] map = new int[100005];
  int [] map1 = new int[100005];
  for(int i = 0; i < l[0]; i++)map[arr[i]] = 0;
  for(int i = 0; i < l[0]; i++)map1[arr1[i]] = 0;

  for(int i = l[1]; i <= l[2]; i++)
   map[arr[i]] = map[arr[i]] + 1;
  for(int i = l[1]; i <= l[2]; i++)
   map1[arr1[i]] = map1[arr1[i]] + 1;
  for(int i = l[1]; i <= l[2]; i++)
   if(map[arr[i]] != map1[arr[i]])
    flag = false;

  if(flag == true)Console.WriteLine("TRUTH");
  else Console.WriteLine("LIE");

    }
}