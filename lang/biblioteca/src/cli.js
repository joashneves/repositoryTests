import fs from 'fs';
import trataErro from './error/funcoesErro.js';
import { contaPalavra } from './index.js';
import { montaSaidaArquivo } from './helper.js';

const caminhoArgumento = process.argv;
const link = caminhoArgumento[2];
const endereco = caminhoArgumento[3]

fs.readFile(link, 'utf-8', (erro, texto) => {
  try{
  if (erro) throw erro;
  const resultado = contaPalavra(texto);
  criarESalvarArquivo(resultado, endereco)
} catch(erro){
  trataErro(erro);
}
})

async function criarESalvarArquivo(listaPalavras, endereco){
  const arquivoNovo = `${endereco}/resultado.txt`;
  const textoPalavra = montaSaidaArquivo(listaPalavras)
  try{
    await fs.promises.writeFile(arquivoNovo, textoPalavra);
    console.log("Arquivo Criado")
  }catch(erro){
    throw erro;
  }
}