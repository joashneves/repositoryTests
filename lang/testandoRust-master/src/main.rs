use std::string;

fn main() {
    struct pessoa {
        id: u128,
        nome: String,
    }
    
    let id:u128;
    let nome:String;
    
    while true {
        print!("Escreva seu nome");
        let mut escolher = String::new();
        
        let b1 = std::io::stdin().read_line(&mut escolher).unwrap();

        println!("Seu nome é {}", escolher);
        return;
        
    }
}
