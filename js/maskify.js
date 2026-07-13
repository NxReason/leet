function maskify(cc) {
  if (cc.length < 4) return cc;

  return '#'.repeat(cc.length - 4) + cc.slice(-4);
}

console.log(maskify('1'));
console.log(maskify('231'));
console.log(maskify('3563246351'));
console.log(maskify('I am batman'));
