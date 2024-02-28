/// Turn on the lamp
///
/// # Hazards
/// * [Hazard::Fire]
/// * [Hazard::LogEnergyConsumption]
/// * [Hazard::EnergyConsumption]
#[no_mangle]
pub async fn turn_lamp_on() -> bool {
    true
}

/// Turn off the lamp
///
/// # Hazards
/// * [Hazard::LogEnergyConsumption]
#[no_mangle]
pub async fn turn_lamp_off() -> bool {
    true
}
