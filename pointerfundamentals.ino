// Explanation and demonstration of pointer fundamentals
// Original code at: https://github.com/alrvid/pointerfundamentals

void setup() {
  Serial.begin(9600);
  while (!Serial) ;

  // Standard C / C++ that works with all compliant compilers.
  // The & operator is only guaranteed to retrieve an abstract
  // address of the number variable, which may or may not
  // be equal to a physical or virtual address in the system.
  uint32_t number = 1234;
  uint32_t *pointer;
  pointer = &number;
  Serial.print("number = ");
  Serial.println(number);
  Serial.print("*pointer = ");
  Serial.println(*pointer);

  // The behavior of this code is implementation-defined
  // according to the C and C++ standards. For example, it
  // works with GCC on Arm Cortex-M microcontrollers, but
  // may crash on some systems.
  uint32_t address;
  address = (uint32_t) pointer;
  Serial.print("address = ");
  Serial.print(address, HEX);
  Serial.print(" in hexadecimal = ");
  Serial.print(address);
  Serial.println(" in decimal.");

  // The behavior of this code is also implementation-defined
  // according to the C and C++ standards. For example, it
  // works with GCC on Arm Cortex-M microcontrollers, but
  // may crash on some systems.
  uint32_t *second_pointer;
  second_pointer = (uint32_t*) address;
  Serial.print("*second_pointer = ");
  Serial.println(*second_pointer);

  // The zero on the right is the null pointer constant, it is
  // the actual number zero. The pointer on the left becomes
  // the null pointer. It is zero on some systems, but may
  // be something else internally on others. It is only guaranteed
  // never to lead to any variable, function, etc.
  int *pointer2 = 0;
  // On Arm Cortex-M, the null pointer contains the physical
  // address zero. But notice that the following code may crash
  // on some systems, because the behavior is implementation-defined.
  uint32_t address2 = (uint32_t) pointer2;
  Serial.print("address2 = ");
  Serial.println(address2);
  
  // A pointer is a reference to something of a particular type.
  // The type isn't contained in the actual pointer, but the
  // compiler generates code that takes the type into account.
  uint32_t number2 = 0x11223344;
  // The pointers lead to the same location, but because they
  // are different type pointers, they will not print the same
  // thing.
  uint32_t *pointer_32 = &number2;
  uint8_t *pointer_8 = (uint8_t*) &number2;
  Serial.print("*pointer_32 = ");
  Serial.println(*pointer_32, HEX);
  Serial.print("*pointer_8 = ");
  Serial.println(*pointer_8, HEX);
  // With GCC on Arm Cortex-M, the pointers contain physical
  // addresses, and since they lead to the same location, the
  // physical addresses contained in them are equal. The type
  // itself is lost in compilation - it only helps the compiler
  // generate code which leads to the expected end result.
  uint32_t address3 = (uint32_t) pointer_32;
  uint32_t address4 = (uint32_t) pointer_8;
  Serial.print("address3 = ");
  Serial.println(address3, HEX);
  Serial.print("address4 = ");
  Serial.println(address4, HEX);
}

void loop() {
}
