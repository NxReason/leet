public class Kata
{
  public static string ToCamelCase(string str)
  {
    char[] delimeters = new char[] { '_', '-' };
    string[] words = str.Split(delimeters);
    for (int i = 1; i < words.Length; i++)
    {
      words[i] = char.ToUpper(words[i][0]) + words[i].Substring(1);
    }
    return string.Join("", words);
  }

  public static string HighAndLow(string numbers)
  {
    string[] numbersArr = numbers.Split(' ');
    int high = int.Parse(numbersArr[0]);
    int low = high;
    foreach (var num in numbersArr)
    {
      int value = int.Parse(num);
      if (value > high) high = value;
      if (value < low) low = value;
    }

    return $"{high} {low}";
  }
}