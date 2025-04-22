function filtrarOcorrencia(paragrafos){
  return Object.keys(paragrafos).filter(chave => paragrafos[chave] > 1)
}

function montaSaidaArquivo(listaPalavras){
  let textoFinal = "";
  listaPalavras.forEach((paragrafos, indice) => {
    const duplicado = filtrarOcorrencia(paragrafos).join(', ');
    textoFinal += `palavras duplicadas no paragrafos ${indice + 1}: 
     ${duplicado} \n`
    
  });
  return textoFinal;
}

export { montaSaidaArquivo}