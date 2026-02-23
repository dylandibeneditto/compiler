use std::env;
use std::process::exit;

mod scan;
use scan::Scan;

fn main() {
    let args: Vec<String> = env::args().collect();
    let scan = Scan::new();

    match args.len() {
        n if n > 2 => {
            println!("Usage: ditto [filename]");
            exit(64);
        }
        2 => {
            let path = &args[1];
            scan.run_file(path);
        }
        _ => {
            scan.run_prompt();
        }
    }
}
