import 'package:flutter/foundation.dart';

enum Complexity {
  ForBeginners,
  Easy,
  Advanced,
  Hard,
}

class Exercise {
  final String id;
  final List<String> categories;
  final String title;
  final String workoutArea;
  final Complexity complexity;
  final String image;
  final List<String> preparation;
  final List<String> steps;
  final int duration;
  final bool isEasy;
  final bool isForBeginners;
  final bool isAdvanced;
  final bool isHard;

  const Exercise(
      {required this.id,
      required this.title,
      required this.categories,
      required this.workoutArea,
      required this.complexity,
      required this.image,
      required this.preparation,
      required this.steps,
      required this.duration,
      required this.isForBeginners,
      required this.isAdvanced,
      required this.isEasy,
      required this.isHard});
}
