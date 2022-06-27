//import 'dart:html';

//import 'dart:html';

import 'package:flutter/src/foundation/key.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:flutter/material.dart';
//import 'package:workoutapp/Widgets/note_detail.dart';
import 'package:workoutapp/models/note_model.dart';
import 'package:intl/intl.dart';
import 'package:workoutapp/screens/notes_screen.dart';

class NotesList extends StatelessWidget {
  //const TransactionList({Key? key}) : super(key: key);
  final List<Note> notes;
  final Function deleteTx;

  NotesList(this.notes, this.deleteTx);

  void selectNote(BuildContext context, String id, String text, String title) {
    Navigator.of(context).pushNamed('/test');
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      height: MediaQuery.of(context).size.height * 1,
      child: notes.isEmpty
          ? Column(
              children: <Widget>[
                SizedBox(
                  height: 20,
                ),
                Container(
                  alignment: Alignment.center,
                  child: Text(
                    'No Notes added yet', style: TextStyle(fontSize: 25),
                    textAlign: TextAlign.end,
                    //style: Theme.of(context).textTheme.headline6,
                  ),
                ),
                SizedBox(
                  height: 10,
                ),
                Container(
                    height: 250,
                    child: Image.asset('assets/pen.png', fit: BoxFit.cover)),
              ],
            )
          : ListView.builder(
              itemBuilder: (ctx, index) {
                return Card(
                  elevation: 5,
                  margin: EdgeInsets.symmetric(vertical: 8, horizontal: 5),
                  child: ListTile(
                    leading: CircleAvatar(
                      radius: 30,
                      child: Padding(
                        padding: EdgeInsets.all(6),
                        child: FittedBox(
                            child: Text(
                          '${index + 1}',
                          style: TextStyle(fontSize: 25),
                        )),
                      ),
                    ),
                    title: Text(notes[index].title,
                        style: Theme.of(context).textTheme.headline6),
                    subtitle: Text(notes[index].text),
                    trailing: IconButton(
                        icon: Icon(Icons.delete),
                        color: Color.fromARGB(255, 157, 17, 181),
                        onPressed: () => deleteTx(notes[index].id)),
                  ),
                );
              },
              itemCount: notes.length,
            ),
    );
  }
}
