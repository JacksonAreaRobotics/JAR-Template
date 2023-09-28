float reduce_0_to_360(float angle);

float reduce_negative_180_to_180(float angle);

float reduce_negative_90_to_90(float angle);

float to_rad(float angle_deg);

float to_deg(float angle_rad);

float clamp(float input, float min, float max);

bool is_reversed(double input);

float to_volt(float percent);

int to_port(int port);

float deadband(float input, float width);