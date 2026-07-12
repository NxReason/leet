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
}