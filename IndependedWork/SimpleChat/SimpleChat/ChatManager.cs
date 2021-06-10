using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SimpleChat
{
    public delegate void LogHandler(object sender, string message);

    public class ChatManager
    {
        List<User> _activeUsers = new List<User>();
        public event MessageHandler OnMessage;
        public event UserCountChanged OnUserNumberChanged;
        public event LogHandler OnLog;
        int userCounts;

        public ChatManager()
        {
            OnMessage += (mes) =>
            {
                _activeUsers.ForEach(d =>
                {
                    d.Receive(mes);
                });
            };
        }

        public void AddUser(User user)
        {
            if (_activeUsers.Contains(user))
                return;

            OnUserNumberChanged(this, ++userCounts);
            _activeUsers.Add(user);
            user.OnSent += (mes) =>
            {
                OnMessage(mes);
            };
            OnLog(this, $"{DateTime.Now.ToString("T")} {user.Username} joined chat");
        }

        public void RemoveUser(User user)
        {
            if (!_activeUsers.Contains(user))
                return;

            OnUserNumberChanged(this, --userCounts);

            OnLog(this, $"{DateTime.Now.ToString("T")} {user.Username} leaved from chat");
            _activeUsers.Remove(user);
        }
    }
}
