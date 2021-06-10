﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleChat
{
    public class User
    {
        public string Username { get; set; }

        public event MessageHandler OnSent;
        public event MessageHandler OnReceived;

        List<Message> _history = new List<Message>();
        bool a;
        public List<Message> History
        {
            get
            {
                return _history;
            }
        }

        public User(string name)
        {
            Username = name;
        }

        public void Send(string data)
        {
            var newMessage = new Message { Data = data, Initiator = this, TimeStamp = DateTime.Now };
            _history.Add(newMessage);
            if (OnSent != null)
                OnSent(newMessage);
        }

        public void Receive(Message message)
        {
            _history.Add(message);
            if (OnReceived != null)
                OnReceived(message);
        }
    }
}
