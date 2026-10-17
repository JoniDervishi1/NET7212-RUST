fn main() {
    let in_order = {
        let people = [String::from("John Doe"), String::from("Jane Eyre"), String::from("Jane Doe")];
        sorted(&people)
    }; //in_oder is holding references to people, which is going out of scope here and therefore destroyed
    for n in in_order {
        println!("- {n}");
    }
}

pub enum StringOrRef<'a> {
    Owned(String),
    Borrowed(&'a str), //'a is generic lifetime of the data. and &'a str means a reference to a str of lifetime 'a
}

fn display(x: &StringOrRef<'_>) {  // '_ means that the lifetime has no importance here
    match x {
        StringOrRef::Owned(s) => println!("owned string: {s}"),
        StringOrRef::Borrowed(s) => println!("borrowed string: {s}"),
    }
}
pub fn as_str<'a>(x: &'a StringOrRef<'_>) -> &'a str {
    match x {
        StringOrRef::Owned(s) => &s,
        StringOrRef::Borrowed(s) => s,
    }
}


fn sorted(names: &[String]) -> Vec<&String> {
    let mut vector = vec![];
    for name in names{
        vector.push(name);
    } 
    vector.sort();
    vector
}

/*
fn smallest_first(a: &mut i32, b: &mut i32) {
    if a >= b{
        std::mem::swap(a, b);
    }
    //(a, b)
}

fn do_swap() {
    let mut a = String::from("apple");
    let mut b = String::from("bread");
    println!("Before swap: a = {a}, b = {b}");
    std::mem::swap(&mut a, &mut b); // REPLACE ME with something using std::mem::swap()
    println!("After swap: a = {a}, b = {b}");
}
*/