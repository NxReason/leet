export default function assert(expected, actual) {
  const match = expected === actual;
  console.log(`[${match ? 'success' : 'error'}] ${expected} === ${actual}`);
}
