/*
 * This file is part of OpenCorsairLink.
 * Copyright (C) 2017-2019  Sean Nelson <audiohacked@gmail.com>

 * OpenCorsairLink is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * any later version.

 * OpenCorsairLink is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with OpenCorsairLink.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "device.h"

#include "driver.h"

#include <libusb.h>

struct corsair_device_info corsairlink_devices[] = {
    {
        .vendor_id = 0x1b1c,
        .product_id = 0x0c10,
        .device_id = 0xFF,
        .name = "Commander PRO", /* Barbuda */
        .read_endpoint = 0x01 | LIBUSB_ENDPOINT_IN,
        .write_endpoint = 0x02 | LIBUSB_ENDPOINT_OUT,
        .driver = &corsairlink_driver_commanderpro,
        .lowlevel = &corsairlink_lowlevel_commanderpro,
        .led_control_count = 2,
        .fan_control_count = 6,
        .pump_index = 0,
    },
};

uint8_t corsairlink_device_list_count =
    sizeof( corsairlink_devices ) / sizeof( corsairlink_devices[0] );
