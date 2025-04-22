const fs = require('fs')

const caminhoArgumento = process.argv;
const link = caminhoArgumento[2]

fs.readFile(link, 'utf-8', (error, texto) => {
  quebraEmParagrafos(texto)
})

function quebraEmParagrafos(texto){
  const paragrafos = texto.toLowerCase().split('\r').join('').split('\n');
  const contagem = paragrafos.flatMap((paragrafos)=>{
    if(!paragrafos) return []
    return verificaPalavraDuplicada(paragrafos)
  })
  console.log(contagem)
}

function limparPalavra(palavra){
  return palavra.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g, '');
}

function verificaPalavraDuplicada(texto){
  const listaPalavras = texto.split(' ');
  const resultado = {};
  listaPalavras.forEach(palavra => {
    if (palavra.length >= 3){
      const palavraLimpa = limparPalavra(palavra);
      resultado[palavraLimpa] = (resultado[palavraLimpa] ||  0) + 1 
    }
  });
  return resultado
}