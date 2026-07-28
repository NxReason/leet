function longestCommonPrefix(strs) {
  const shortestStr = Math.min(...strs.map(s => s.length));
  let out = '';

  for (let i = 0; i < shortestStr; i++) {
    if (new Set(strs.map(s => s[i])).size === 1) out += strs[0][i];
    else break;
  }

  return out;
}

function runLongestCommonPrefix() {
  console.log(longestCommonPrefix(['flower', 'flow', 'flight']));
  console.log(longestCommonPrefix(['dog', 'racecar', 'car']));
}

runLongestCommonPrefix();
