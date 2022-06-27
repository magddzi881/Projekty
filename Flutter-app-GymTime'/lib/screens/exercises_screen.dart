import 'package:flutter/material.dart';
import 'package:flutter/src/foundation/key.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:workoutapp/Widgets/exercise_item.dart';
import 'package:workoutapp/data.dart';

class ExercisesScreen extends StatefulWidget {
  // const ExercisesScreen({Key? key}) : super(key: key);

  @override
  State<ExercisesScreen> createState() => _ExercisesScreenState();
}

class _ExercisesScreenState extends State<ExercisesScreen> {
  @override
  Widget build(BuildContext context) {
    return ListView(
      padding: const EdgeInsets.all(15),
      children: listOfExercises
          .map(
            (catData) => ExerciseItem(
              complexity: catData.complexity,
              duration: catData.duration,
              id: catData.id,
              imageUrl: catData.image,
              title: catData.title,
              workoutArea: catData.workoutArea,
            ),
          )
          .toList(),
    );
  }
}
