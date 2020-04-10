fn main() {
    // wrong: type annotation needed
    // let guess = "42".parse().expect("Not a number!");
    // correct
    let guess: u32 = "42".parse().expect("Not a number!");
    println!("{}", guess);

    // Floating-Point Types
    let x = 2.0; // f64 by default
    println!("{}", x);
    let y: f32 = 3.0; // f32 explisitly
    println!("{}", y);

    // Tuples
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    // or
    let tup = (500, 6.4, 1);

    let (x, y, z) = tup; // destructing

    let tup = (500, 6.4, 1);
    println!("{}", tup.0);
    println!("{}", tup.1);
    println!("{}", tup.2);

    // Arrays
    let a = [1, 2, 3, 4, 5];
    let index = 10;
    let element = a[index];
    println!("The value of element is: {}", element);
}
