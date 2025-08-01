pub fn production_rate_per_hour(speed: u8) -> f64 {
    let produced_cars = speed as f64 * 221.0;
    let success_rate = match speed {
        0 => 0.0,
        1..=4  => 1.0,
        5..=8  => 0.9,
        9..=10 => 0.77,
        _ => panic!("Error: speed must be between 0 and 10 inclusive")
    };
    success_rate * produced_cars
}

pub fn working_items_per_minute(speed: u8) -> u32 {
    (production_rate_per_hour(speed) / 60.0).floor() as u32
}
