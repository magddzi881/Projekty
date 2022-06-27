import 'package:flutter/material.dart';
import 'package:flutter/src/foundation/key.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:workoutapp/Widgets/main_drawer.dart';
import 'package:workoutapp/Widgets/new_note.dart';
import 'package:workoutapp/Widgets/notes_list.dart';
import 'package:workoutapp/models/exercise_model.dart';
import 'package:workoutapp/models/note_model.dart';

class NotesScreen extends StatefulWidget {
  //const NotesScreen({Key? key}) : super(key: key);
  static const routeName = '/notes';

  @override
  State<NotesScreen> createState() => _NotesScreenState();
}

class _NotesScreenState extends State<NotesScreen> {
  final List<Note> userNotes = [];

  void addNewNote(String txTitle, String txText, DateTime chosenDate) {
    final newTx = Note(
      title: txTitle,
      text: txText,
      date: chosenDate,
      id: DateTime.now().toString(),
    );

    setState(() {
      userNotes.add(newTx);
    });
  }

  void startAddingNote(BuildContext ctx) {
    showModalBottomSheet(
        context: ctx,
        builder: (_) {
          return GestureDetector(
            onTap: () {},
            child: NewNote(addNewNote),
            behavior: HitTestBehavior.opaque,
          );
        });
  }

  void deleteNote(String id) {
    setState(() {
      userNotes.removeWhere((tx) {
        return tx.id == id;
      });
    });
  }

  List<Exercise> exercises = [];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      drawer: MainDrawer(exercises),
      appBar: AppBar(
        title: Text('My notes'),
        actions: <Widget>[
          IconButton(
              onPressed: () => startAddingNote(context), icon: Icon(Icons.add))
        ],
      ),
      body: SingleChildScrollView(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.start,
          children: <Widget>[
            NotesList(userNotes, deleteNote)
            //Checkbox(value: mounted, onChanged: (_) {})
            //UserTransactions(),
          ],
        ),
      ),
      floatingActionButtonLocation:
          FloatingActionButtonLocation.miniCenterFloat,
      floatingActionButton: FloatingActionButton(
        child: Icon(Icons.add),
        onPressed: () => startAddingNote(context),
      ),
    );
  }
}
