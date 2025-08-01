// ovenTime returns the amount in minutes that the lasagna should stay in the
// oven.
[[nodiscard]] static constexpr int ovenTime() {
    return 40;
}

/* remainingOvenTime returns the remaining
   minutes based on the actual minutes already in the oven.
*/
[[nodiscard]] static constexpr int remainingOvenTime(int actualMinutesInOven) {
    // TODO: Calculate and return the remaining in the oven based on the time
    // the lasagna has already been there.
    return ovenTime() - actualMinutesInOven;
}

/* preparationTime returns an estimate of the preparation time based on the
   number of layers and the necessary time per layer.
*/
[[nodiscard]] static constexpr int preparationTime(int numberOfLayers) {
    return 2 * numberOfLayers;
}

// elapsedTime calculates the total time spent to create and bake the lasagna so
// far.
[[nodiscard]] static constexpr int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    // TODO: Calculate and return the total time so far.
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}
