// This file is part of the IMP project.

#pragma once

#include <cassert>
#include <cstdint>
#include <cstring>
#include <vector>
#include <ostream>



/**
 * Enumeration of the opcodes supported by the interpreter.
 */
enum class Opcode : uint8_t {
  PUSH_FUNC,
  PUSH_PROTO,
  // lab 1 ex 4 a

  PUSH_INT,

  PEEK,
  POP,
  CALL,

  ADD,
  RET,

  JUMP_FALSE,
  JUMP,
  STOP
  
};

/**
 * Prints the opcode to a stream, for debugging.
 */
std::ostream &operator<<(std::ostream &os, Opcode op);


/**
 * Holds the bytecode for a program.
 */
class Program {
public:

  Program(std::vector<uint8_t> &&code) : code_(std::move(code)) {}

  /// Read a value from a specific location.
  template<typename T>
  T Read(size_t &pc)
  {
    T t;
    assert(pc + sizeof(T) <= code_.size());
    memcpy(&t, code_.data() + pc, sizeof(T));
    pc += sizeof(T);
    return t;
  }

private:
  std::vector<uint8_t> code_;
};