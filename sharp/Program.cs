List<int> values = new() { 42, 151, 2332, 144 };

foreach (int value in values)
{
  Console.WriteLine(Kata.IsPalindrome(value));
}