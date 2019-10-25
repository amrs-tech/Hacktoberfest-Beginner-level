/// @description Insert description here
// You can write your code in this editor


// while the player is touching or clicking update the control sticks position
if device_mouse_check_button(0,mb_left){
	x = device_mouse_x(0);
	y = device_mouse_y(0);
	
	visible = true;
}

// reset upon the player releasing
if device_mouse_check_button_released(0,mb_left){
	visible = false;
}