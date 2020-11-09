#ifndef __GREEN_CONFIG_H
#define __GREEN_CONFIG_H

#ifndef GREEN_CONFIG_USE_GPIO_PIN
  #define GREEN_CONFIG_USE_GPIO_PIN   (1)
    /*!< 1: use GPIO pin; 0: use PWM pin */
#endif

#ifndef GREEN_CONFIG_IS_LOW_ACTIVE
  #define GREEN_CONFIG_IS_LOW_ACTIVE   (1)
    /*!< 1: LED is low active (cathode on port side), 0: LED is HIGH active (anode on port side) */
#endif

#endif /* __GREEN_CONFIG_H */
