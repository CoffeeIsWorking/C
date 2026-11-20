use std::io;

struct Vectors{
    number_vector: Vec<i32>,
    variable_vector: Vec<char>
}

pub fn input_parsing(input:&str) -> Result<Vectors,&str>{
    
    Vectors vector{
        .number_vector = Vec::new();
    };


    for item in input.chars() {
        
        if item.is_alphanumeric() {
            if item.is_numeric(){
                
                number_vector.push(item.to_digit(10).unwrap() as i32);
            }

            else if item.is_alphabetic(){
                variable_vector.push(item);
            }

            else{
                Err("fahh")?
            };
        };
    };
}


pub fn matrix_solver(number: i32,number_vector: Vec<i32>, 
    variable_vector: Vec<char> ) -> (){

    let a: i32 = 0;
    let detA: i64;


}



fn main() {
    let mut temp_string = String::new();

    io::stdin()
        .read_line(&mut temp_string)
        .expect("Fuck you niga");

    let mut num: i32 = temp_string
        .trim()
        .parse()
        .expect("What?");
     
    while num > 0 {

        let mut string_temp_line_input = String::new();

        io::stdin()
            .read_line(&mut string_temp_line_input)
            .expect("why?");
            
        input_parsing(&string_temp_line_input);
        num = num - 1;
    }
    
}
