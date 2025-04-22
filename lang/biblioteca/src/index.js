const fs = require('fs')
const trataErro = require('./funcoesErro.js')
const caminhoArgumento = process.argv;
const link = caminhoArgumento[2]

fs.readFile(link, 'utf-8', (erro, texto) => {
  try{
  if (erro) throw erro;
  contaPalavra(texto)
} catch(erro){
  trataErro(erro);
}
})

function contaPalavra(texto){
  const paragrafos = extraiParagrafos(texto)
  const contagem = paragrafos.flatMap((paragrafos)=>{
    if(!paragrafos) return []
    return verificaPalavraDuplicada(paragrafos)
  })
  console.log(contagem)
}

function extraiParagrafos(texto){
  return texto.toLowerCase().split('\r').join('').split('\n');

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