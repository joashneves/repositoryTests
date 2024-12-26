# calculadora.rb

class Calculadora
    def initialize(calculo)
      @calculo = calculo.chomp
      @novo_calculo = @calculo.split("")
      @array_numero = []
      @array_operador = []
      @result = nil
    end
  
    def processar_calculo
      puts "\n"
      print @novo_calculo
      puts "\n"
  
      # Processa os caracteres da expressão
      numero_atual = ""
      @novo_calculo.each do |char|
        if ["+", "-", "*", "/"].include?(char)
          @array_operador << char
          if !numero_atual.empty?
            @array_numero << numero_atual.to_i
            numero_atual = ""
          end
        elsif char =~ /\d/
          numero_atual += char
        end
      end
  
      # Adiciona o último número ao array
      @array_numero << numero_atual.to_i unless numero_atual.empty?
  
      puts "Array de números: #{@array_numero}"
      puts "Array de operadores: #{@array_operador}"
  
      calcular_resultado
    end
  
    def calcular_resultado
      @result = @array_numero[0]
      x = 1
      y = 0
  
      while y < @array_operador.size
        operador = @array_operador[y]
        numero = @array_numero[x]
  
        puts "Processando: #{@result} #{operador} #{numero}"
  
        case operador
        when "+"
          @result += numero
        when "-"
          @result -= numero
        when "*"
          @result *= numero
        when "/"
          if numero == 0
            puts 'Não é possível dividir por 0'
            @result = nil
            break
          else
            @result /= numero
          end
        else
          puts 'Operação inválida'
        end
  
        x += 1
        y += 1
      end
  
      imprimir_resultado
    end
  
    def imprimir_resultado
      if @result
        puts "Resultado: #{@calculo} = #{@result}"
      else
        puts "Cálculo inválido ou divisão por zero."
      end
    end
  end
  