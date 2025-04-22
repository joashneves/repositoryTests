const fs = require('fs')

const caminhoArgumento = process.argv;
const link = caminhoArgumento[2]

fs.readFile(link, 'utf-8', (error, texto) => {
  console.log(texto)
})

console.log(link)