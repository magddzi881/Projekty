import 'package:flutter/material.dart';
import 'package:flutter/src/foundation/key.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:workoutapp/data.dart';
import '../Widgets/category_item.dart';

class TrainingScreen extends StatefulWidget {
  const TrainingScreen({Key? key}) : super(key: key);

  @override
  State<TrainingScreen> createState() => _TrainingScreenState();
}

class _TrainingScreenState extends State<TrainingScreen> {
  @override
  Widget build(BuildContext context) {
    return GridView(
      padding: const EdgeInsets.all(15),
      children: listOfCategories
          .map(
            (catData) => CategoryItem(
              catData.id,
              catData.title,
              catData.color,
            ),
          )
          .toList(),
      gridDelegate: SliverGridDelegateWithMaxCrossAxisExtent(
        maxCrossAxisExtent: 400,
        childAspectRatio: 3 / 1,
        crossAxisSpacing: 20,
        mainAxisSpacing: 20,
      ),
    );
  }
}
