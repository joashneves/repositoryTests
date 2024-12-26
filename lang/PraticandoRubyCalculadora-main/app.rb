
require_relative 'calculadora'

def calcular_ror (lambida, unidade_tempo)
  ror = lambida / unidade_tempo
  if lambida < unidade_tempo
    lambida / unidade_tempo
  elsif ror > 1 
    puts 'Fila infinita'
  end
  puts ror
  return ror
end

def pi_zero ()

puts "Fazer calculo: \n 1 - Calculadora \n 2 - Custo total"
opcao = "2"
puts opcao
case opcao
when "1"
  calculo = gets
  calculadora = Calculadora.new(calculo)
  calculadora.processar_calculo
when "2"
  puts "Taxa Media de chegada ="
  lambida = gets.to_f
  puts "Taxa Media de Atendimento ="
  unidade_tempo = gets.to_f
  puts "Servidores ="
  servidores = gets.to_f
  ror = calcular_ror(lambida, unidade_tempo)
  puts ror
else 
  puts "Opção invalida"
end
