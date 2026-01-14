function parseMolecule(formula: string): { [key: string]: number } {
  const result: { [key: string]: number } = {};
  const stack: { [key: string]: number }[] = [{}];
  let i = 0;

  while (i < formula.length) {
    const char = formula[i];

    if (char === '(' || char === '[' || char === '{') {
      stack.push({});
      i++;
    }
    else if (char === ')' || char === ']' || char === '}') {
      i++;
      let multiplier = 0;
      while (i < formula.length && /\d/.test(formula[i])) {
        multiplier = multiplier * 10 + parseInt(formula[i]);
        i++;
      }
      if (multiplier === 0) multiplier = 1;

      const top = stack.pop()!;
      const current = stack[stack.length - 1];
      
      for (const element in top) {
        current[element] = (current[element] || 0) + top[element] * multiplier;
      }
    }
    else if (/[A-Z]/.test(char)) {
      let element = char;
      i++;
      while (i < formula.length && /[a-z]/.test(formula[i])) {
        element += formula[i];
        i++;
      }

      let count = 0;
      while (i < formula.length && /\d/.test(formula[i])) {
        count = count * 10 + parseInt(formula[i]);
        i++;
      }
      if (count === 0) count = 1;

      const current = stack[stack.length - 1];
      current[element] = (current[element] || 0) + count;
    }
    else {
      i++;
    }
  }

  return stack[0];
}

console.log(parseMolecule('H2O'));
console.log(parseMolecule('Mg(OH)2'));
console.log(parseMolecule('K4[ON(SO3)2]2'));
console.log(parseMolecule('Fe(NO3)2'));
console.log(parseMolecule('Ca(OH)2'));
console.log(parseMolecule('{[Co(NH3)4(OH)2]3Co}(SO4)3'));
