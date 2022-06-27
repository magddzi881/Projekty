import 'package:flutter/material.dart';

class Note {
  final String id;
  final String title;
  final String text;
  final DateTime date;

  Note(
      {required this.id,
      required this.title,
      required this.text,
      required this.date});
}
