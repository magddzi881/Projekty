import 'package:flutter/material.dart';

class Categoryy {
  final String id;
  final String title;
  final Color color;

  const Categoryy({
    required this.id,
    required this.title,
    this.color = Colors.deepPurpleAccent,
  });
}
