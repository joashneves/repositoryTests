<?php
$idadeAluno = 28;

if ($idadeAluno >= 18) {
  echo ('Maior que 18 anos');
} else if ($idadeAluno <= 18) {
  echo ('menor que 18');
}
echo "<br>";

$array_color = array("vermelho", "verde", "azul", "amarelo", "roxo");
//echo "$array_color";
foreach ($array_color as $color) {
  echo "$color <br>";
}

echo "<br>";
for ($i = 0; $i <= 10; $i++) {
  if ($i % 2 == 0) {
    echo "$i";

    echo "<br>";
  }
}

$nota_aluno = ["matematica" => 7.5,
 "portugues" => 8.0,
 "historia" => 6.0,
 "ciencias" => 9.0];
echo '<br>';
 foreach($nota_aluno as $nota => $valor){
  if($valor >= 7){
    echo "<br> $nota : $valor";
  }
 }